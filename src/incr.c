/**
 * @file	incr.c
 * @author	Albert Kharisov
 * @date	27/03/2019
 *
 * @brief	Test task to AURA company. Increment variable.
 */


#include <limits.h>
#include "incr.h"
#include "assert.h"


/**
 * @brief	Validates \p number consistency.
 * 		It should be less than \p max_number.
 */
#define WRAPARAOUND_CHECK()	do { if (number >= max_number) number = 0; } while (0)


static int number = 0;
static int max_number = INT_MAX;


int numberGet(void)
{
	return number;
}

void numberInc(void)
{
	++number;
	WRAPARAOUND_CHECK();
}

void numberMaxvalSet(int maximumValue)
{
	if (maximumValue < 0) {
		WARN(0);
		return;
	}
	max_number = maximumValue;
	WRAPARAOUND_CHECK();
}

