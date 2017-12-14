/**
 * \file hptsc.h

 * This low level part must provide the following types, macros and/or
 * functions.
 * - HptscTicks_t
 * - HPTSC_COUNTER_MSK
 * - hptsc_Init()
 * - hptsc_Cleanup()
 * - hptsc_Timestamp()
 */

#if !defined _HPTSC_H_
#define _HPTSC_H_

#include <stdbool.h>
#include "comdefs.h"
#include "DSP2803x_Device.h"

#define HPTSC_COUNTER_MSK 0xFFFFFFFF   
/*HPTSC Config*/
#define CONFIG_HPTSC_HZ   CPU_TIME0_FREQUENCY  //select timer0

typedef unsigned long HptscTicks_t;


#if !defined CONFIG_HPTSC_HZ
#error "CONFIG_HPTSC_HZ must be defined"
#endif

#if !defined HPTSC_COUNTER_MSK
#error "Low level driver must be include"
#endif

static inline HptscTicks_t hptsc_Timestamp(void)
{
    HptscTicks_t now = CpuTimer0Regs.TIM.all;

    /*
     * The systick timer is a down counter, but we have to return
     * an up-counting timestamp.
     */
    return HPTSC_COUNTER_MSK - now;
}

/* -------------------------------------------------------------------- */
/* Pure timestamp related functions.                                    */
/* -------------------------------------------------------------------- */

/**
 * Convert time in [sec] into ticks, target data type specified by user.
 *
 * \param[in] type The data type used to hold the resulting ticks.
 * \param[in] sec Time in [sec].
 *
 * \returns
 * Number of ticks representing the given time.
 */
#define hptsc_SecToTicksUserType(type, sec) \
    ROUND_TO(type, (double) CONFIG_HPTSC_HZ * (sec))

/**
 * Convert time in [ms] into ticks, target data type specified by user.
 *
 * \param[in] type The data type used to hold the resulting ticks.
 * \param[in] ms Time in [ms].
 *
 * \returns
 * Number of ticks representing the given time.
 */
#define hptsc_MsToTicksUserType(type, ms) \
    ROUND_TO(type, (double) CONFIG_HPTSC_HZ * (ms) / 1000.0)

/**
 * Convert time in [us] into ticks, target data type specified by user.
 *
 * \param[in] type The data type used to hold the resulting ticks.
 * \param[in] us Time in [us].
 *
 * \returns
 * Number of ticks representing the given time.
 */
#define hptsc_UsToTicksUserType(type, us) \
    ROUND_TO(type, (double) CONFIG_HPTSC_HZ * (us) / 1000000.0)

/**
 * Convert time in [sec] into ticks, target data type HptscTicks_t.
 *
 * \param[in] sec Time in [sec].
 *
 * \returns
 * Number of ticks representing the given time.
 */
#define hptsc_SecToTicks(sec) hptsc_SecToTicksUserType(HptscTicks_t, sec)

/**
 * Convert time in [ms] into ticks, target data type HptscTicks_t.
 *
 * \param[in] ms Time in [ms].
 *
 * \returns
 * Number of ticks representing the given time.
 */
#define hptsc_MsToTicks(ms) hptsc_MsToTicksUserType(HptscTicks_t, ms)

/**
 * Convert time in [us] into ticks, target data type HptscTicks_t.
 *
 * \param[in] us Time in [us].
 *
 * \returns
 * Number of ticks representing the given time.
 */
#define hptsc_UsToTicks(us) hptsc_UsToTicksUserType(HptscTicks_t, us)

/**
 * Gives the time elapsed between two timestamps.
 *
 * \param[in] ts_older
 *      The timestamp which is the older one of the two timestamps.
 * \param[in] ts_newer
 *      The timestamp which is the newer one of the two timestamps.
 */
static inline HptscTicks_t hptsc_Elapsed(
        HptscTicks_t ts_older, HptscTicks_t ts_newer
        )
{
    return ((ts_newer - ts_older) & HPTSC_COUNTER_MSK);
}

/**
 * Test if a given period of time is elapsed.
 */
static inline bool hptsc_IsElapsed(
        HptscTicks_t start_time, HptscTicks_t time_span
        )
{
    HptscTicks_t now = hptsc_Timestamp();
    return (hptsc_Elapsed(start_time, now) >= time_span);
}

/**
 * Gives the time elapsed from last.
 *
 * \param[in] p_start_time
 *      Elapsed ticket
 */
static inline HptscTicks_t hptsc_ElapsedTicket(
         HptscTicks_t *p_start_time
        )
{
		HptscTicks_t now = hptsc_Timestamp();
	  if(*p_start_time == 0) //Restart counter
		{
			*p_start_time=now;
		}
		HptscTicks_t st_Elapsed = 0;
		st_Elapsed = hptsc_Elapsed(*p_start_time, now);
        *p_start_time = now;
    return (st_Elapsed & HPTSC_COUNTER_MSK);
}

/**
 * Test if a period of time is elapsed and update start timestamp for
 * repetitive timer user.
 */
static inline bool hptsc_IsElapsedRepetitive(
        HptscTicks_t *p_start_time, HptscTicks_t time_span
        )
{
    HptscTicks_t now = hptsc_Timestamp();

    if (hptsc_Elapsed(*p_start_time, now) >= time_span) {
        *p_start_time = now;
        return true;
    }
    return false;
}

/**
 * Delay execution for a certain number of ticks.
 */
static inline void hptsc_Delay(HptscTicks_t delay)
{
    HptscTicks_t start = hptsc_Timestamp();
    HptscTicks_t now;
    do {
        now = hptsc_Timestamp();
    } while (hptsc_Elapsed(start, now) < delay);
}

/* -------------------------------------------------------------------- */
/* SwTimer-like timer API functions based on timestamps.                */
/* -------------------------------------------------------------------- */

#define HPTSC_TIMER_STOPPED 0U
#define HPTSC_TIMER_EXPIRED 1U

/**
 * Define uninitialized timer based on timestamp counter.
 *
 * \param[in] type
 *      The type of the variable used to hold the timer value.
 *      It must be an unsigned type big enough for the desired time span.
 * \param[in] name
 *      Name of the timer.
 *
 * \note
 * It is up to the user to choose the data type used for the timer value.
 * Therefore we provide this feature as macro instead of an
 * inline function.
 */
#define hptsc_DefineUninitializedTimer(type, name)   \
    struct {                            \
        type value;                     \
        HptscTicks_t ts_last;           \
    } name


/**
 * Constant expression to initialize timer based on timestamp as stopped.
 */
//#define HPTSC_TIMER_STOPPED 0U
#define HPTSC_TIMER_INIT_VAL { HPTSC_TIMER_STOPPED, 0}

/**
 * Define timer based on timestamp counter initialized as stopped.
 *
 * \param[in] type
 *      The type of the variable used to hold the timer value.
 *      It must be an unsigned type big enough for the desired time span.
 * \param[in] name
 *      Name of the timer.
 *
 * \note
 * It is up to the user to choose the data type used for the timer value.
 * Therefore we provide this feature as macro instead of an
 * inline function.
 */
#define hptsc_DefineTimer(type, name) \
    hptsc_DefineUninitializedTimer(type, name) = HPTSC_TIMER_INIT_VAL;

/**
 * Load timer based on timestamp counter with new tick value.
 *
 * \param[in,out] p_tim
 *      Pointer to timer variable created with \a hptsc_DefTimerVar.
 * \param[in] ticks
 *      Period of time to load the timer with.
 */
#define hptsc_LoadTimer(p_tim, ticks)                       \
    do {                                                    \
        (p_tim)->value = ((ticks) + HPTSC_TIMER_EXPIRED);   \
        (p_tim)->ts_last = hptsc_Timestamp();               \
    } while (0)

/**
 * Stop timer based on timestamp counter.
 *
 * \param[in,out] p_tim
 *      Pointer to timer variable created with \a hptsc_DefTimerVar.
 *
 * \note
 * It is up to the user to choose the data type used for the timer value.
 * Therefore we provide this feature as macro instead of an
 */
#define hptsc_StopTimer(p_tim) ((p_tim)->value = HPTSC_TIMER_STOPPED)

/**
 * Check if timer based on timestamp counter has expired.
 *
 * \param[in] p_tim
 *      Pointer to timer variable created with \a hptsc_DefTimerVar.
 *
 * \note
 * It is up to the user to choose the data type used for the timer value.
 * Therefore we provide this feature as macro instead of an
 */
#define hptsc_IsTimerExpired(p_tim) \
    ((p_tim)->value == HPTSC_TIMER_EXPIRED)

/**
 * Check if timer based on timestamp counter is stopped.
 *
 * \param[in] p_tim
 *      Pointer to timer variable created with \a hptsc_DefTimerVar.
 *
 * \note
 * It is up to the user to choose the data type used for the timer value.
 * Therefore we provide this feature as macro instead of an
 */
#define hptsc_IsTimerStopped(p_tim) \
    ((p_tim)->value == HPTSC_TIMER_STOPPED)

/**
 * Check if timer based on timestamp counter is running.
 *
 * \param[in] p_tim
 *      Pointer to timer variable created with \a hptsc_DefTimerVar.
 *
 * \note
 * It is up to the user to choose the data type used for the timer value.
 * Therefore we provide this feature as macro instead of an
 */
 //#define HPTSC_TIMER_EXPIRED 1U
#define hptsc_IsTimerRunning(p_tim) \
    ((p_tim)->value > HPTSC_TIMER_EXPIRED)

/**
 * Get remaining tick from a running timestamp counter.
 *
 * \param[in] p_tim
 *       Pointer to timer variable created with \a hptscDefineTimer
 * \note
 * It is up to the user to choose the data type used for the timer value.
 * Therefore we provide this feature as macro instead of an inline function.
 */
 #define hptsc_GetTimerRemainingTicks(p_tim) \
    (hptsc_IsTimerRunning(p_tim) ? ((p_tim)->value - HPTSC_TIMER_EXPIRED) : 0)
   
        
/**
 * Update timer based on timestamp counter.
 *
 * This macro uses the timestamp coutner to measure the time elapsed
 * since last invocation and updates the timer value accordingly. The
 * time between two invocations must be less than the time duration
 * provided by the High Precision Timestamp Counter minus 2 ticks.
 *
 * \param[in,out] p_tim
 *      Pointer to timer variable created with \a hptsc_DefTimerVar.
 *
 * \note
 * It is up to the user to choose the data type used for the timer value.
 * Therefore we provide this feature as macro instead of an
 */
#define hptsc_UpdateTimer(p_tim)                                    \
    do {                                                            \
        if (hptsc_IsTimerRunning(p_tim)) {                          \
            HptscTicks_t now = hptsc_Timestamp();                   \
            HptscTicks_t elapsed =                                  \
                hptsc_Elapsed((p_tim)->ts_last, now);               \
            (p_tim)->value =                                        \
                (p_tim)->value > (elapsed + HPTSC_TIMER_EXPIRED)    \
                ? (p_tim)->value - elapsed                          \
                : HPTSC_TIMER_EXPIRED;                              \
            (p_tim)->ts_last = now;                                 \
        }                                                           \
    } while(0)

#endif /* !_HPTSC_H_ */
