#ifndef CLA_H_
#define CLA_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CLARAM0_ENABLE		1
#define CLARAM1_ENABLE		1
#define CLARAM0_DISABLE	0
#define CLARAM1_DISABLE	0

//CLA ISRs
__interrupt void cla1_task1_isr( void );
__interrupt void cla1_task2_isr( void );
__interrupt void cla1_task3_isr( void );
__interrupt void cla1_task4_isr( void );
__interrupt void cla1_task5_isr( void );
__interrupt void cla1_task6_isr( void );
__interrupt void cla1_task7_isr( void );
__interrupt void cla1_task8_isr( void );

extern void App_ClaInit(void);

#ifdef __cplusplus
}
#endif /* extern "C" */
#endif /*CLA_H_*/

