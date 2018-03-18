/**
 * \file comdefs.h
 * Common definitions which don't fit somewhere else.
 *
 * ---------------------------------------------------------------------
 */

#if !defined _COMDEFS_H_
#define _COMDEFS_H_

/**
 * Get the number of entries the passed array consists of.
 *
 * \param[in] array
 *      The array for which to determine the number of entries it consists
 *          of.
 * \retval Number of entries the array consists of.
 *
 * \note
 * This macro is evaluated at compile time and gives a constant expression.
 * Therefore it is written in uppercase.
 */
#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))

/**
 * Determines maximum out of two values.
 *
 * \param[in] a The fist value.
 * \param[in] b The second value.
 *
 * \returns \a a if (\a a > \a b), else \a b
 */
#define maximum(a, b) (((a) > (b)) ? (a) : (b))

/**
 * Determines minimum out of two values.
 *
 * \param[in] a The fist value.
 * \param[in] b The second value.
 *
 * \returns \a a if (\a a > \a b), else \a b
 */
#define minimum(a, b) (((a) < (b)) ? (a) : (b))

/**
 * Get the absolute value of a number.
 *
 * \param[in] n Negative or positive value.
 * \returns Absolute value of \n.
 *
 * \note
 * This macros is similar to the abs() function provided by the
 * C standard library, but avoids the overhead of the function call.
 */
#define absolute(n) (((n) < 0) ? (-(n)) : (n))

/**
 * Check if the given value is negative.
 *
 * \param[in] n Value to check for its sign.
 * \retval true Value is negative.
 * \retval false Value is positive.
 */
#define isNegative(n) (n < 0)

/**
 * Fix sign of a value.
 *
 * This macro conditionally changes the sign of \a value based on the
 * condition \a negate.
 *
 * Example for it's use:
 * \code
 * int scale(int v)
 * {
 *     bool neg = isNegative(v);
 *     v = absolute(v);
 *     ...
 *     return fixSign(neg, v);
 * }
 * \endcode
 *
 * \param[in] negate
 *      If true \a value is negated. If false \a value is returned
 *      unchanged.
 * \param[in] value
 *      Value for which to update the sign.
 * \returns Value with updated sign.
 */
#define fixSign(negate, value) ((negate) ? -(value) : (value))

/**
 * Calculate mean value.
 *
 * \param[in] accum Accumulated value from the past.
 * \param[in] shift
 *      Number of bits to right shift \a accum to get the mean value.
 *      For optimization the number of values contributing to
 *      \a accum must be a power of two. Thus we can use a shift operation
 *      to divide the accumulated sum by the number of measurements.
 * \returns
 *      Mean value of the accumulated sum.
 */
#define mean(accum, shift) ((accum) >> (shift))

/**
 * Weighted accumulation to get a consecutive mean value.
 *
 * \param[in] accum Accumulated value from the past.
 * \param[in] new_val The new value contributing the accumulated sum.
 * \param[in] shift The weighting factor as shift value.
 *
 * \returns Updated accumulated value.
 */
#define weightedAccumulation(accum, new_val, shift) \
    (accum) = (accum) + (new_val) - mean(accum, shift)

/**
 * Shift right a value with rounding.
 *
 * \note
 * This macro only works for positive values.
 *
 * \param[in] value Value to shift right.
 * \param[in] shift Number of bits to shift the value right.
 *
 * \return Shifted value.
 */
#define roundedRightShift(value, shift) \
    (((value) + (1 << ((shift) - 1))) >> (shift))

/**
 * Check if a value is in a specified range.
 * 
 * \param[in] val Value to check.
 * \param[in] min_val Minimum value.
 * \param[in] max_val Maximum value.
 *
 * \retval true Value is in range.
 * \retval false Value is not in range.
 */
#define isInRange(val, min_val, max_val) \
    (((val) >= (min_val)) && ((val) <= (max_val)))

/**
 * Round a floating point value to an integer type at compile time.
 *
 * \param[in] type The target data type.
 * \param[in] val  The floating point value to round to the given type.
 *
 * \returns Rounded value cast to the desired type.
 */
#define ROUND_TO(type, val) \
    ((type) ((val) < 0 ? (val) - 0.5 : (val) + 0.5))


/**
 * Conversion of a floating point value to a fractional value (Q15) including
 *   scaling to value less than 1.0 at compile time.
 *
 * \param[in] val   The floating point value to convert.
 * \param[in] shift Scaling of the fractional value.
 *
 * \returns Rounded value cast to the desired type.
 */
#define TO_Q15(val, shift) \
     ROUND_TO(int16_t, (val) * (1L << (15 - (shift))))


/**
 * Increment with wraparound.
 *
 * \param[in,out] p_var
 *      Pointer to the variable to increment by one.
 *
 * \param[in] limit
 *      Upper limit for the value. If the result after increment is
 *      equal or greater the limit, the passed variable is set to 0.
 */
#define incCircular(p_var, limit) \
    (*(p_var) = (((*(p_var) + 1) >= (limit)) ? 0 : (*(p_var) + 1)))

#endif /* !_COMDEFS_H_ */
