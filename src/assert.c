/**
 * @file	assert.c
 * @author	Albert Kharisov
 * @date	27/03/2019
 *
 * @brief	Assert and warn utils.
 *
 * Runtime warnings and assertions.
 * Considers expression 'x' is true. If it's not - call
 * either warn() or assert() to collect failure statistics.
 * warn() is intended for collecting statistics.
 * assert() is same as warn, but performs hard reboot also.
 *
 */


#include <stdio.h>
#include "assert.h"


void warn(const char *file, uint32_t line)
{
	// here is my favourite place to put breakpoint
	printf("warn on %.30s:%d", file, line);
}

void assert(const char *file, uint32_t line)
{
	warn(file, line);
	// perform System Reset here
}

