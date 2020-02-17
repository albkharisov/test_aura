/**
 * @file	incr.h
 * @author	Albert Kharisov
 * @date	27/03/2019
 *
 * @brief	Test task to AURA company. Increment variable.
 */

#ifndef _INCR_H_
#define _INCR_H_


/**
 * @brief 	Get current value of a number.
 * @return	Current value of a number.
 */
int number_get(void);

/**
 * @brief 	Increment number value.
 *
 * Wraparound is applied. As soon as value reachs
 * threshold (maximum value), it is cleared to zero.
 */
void number_inc(void);

/**
 * @brief		Set threshold of a number.
 * @param threshold	Threshold value for a number. Negative threshold
 * 			is forbidden.
 *
 * As soon as number reachs threshold it is cleared to zero.
 * 
 * @note	If number is greater than just set threshold it is
 * 		cleared to zero.
 */
void number_maxval_set(int threshold);

#endif	// _INCR_H_

