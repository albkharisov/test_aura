/**
 * @file	assert.h
 * @author	Albert Kharisov
 * @date	27/03/2019
 *
 * @brief	Assert and warn utils.
 *
 * Provides functions for runtime logging of warnings and assertions.
 *
 */


#ifndef _ASSERT_H_
#define _ASSERT_H_


#include <stdint.h>


/**
 * Intended for collecting runtime failures.
 * Asserts that 'x' expression is true. If not - records place of calling.
 */
#define WARN(x)		do { if (!x) warn(__FILE__, __LINE__); } while(0)

/**
 * Intended for collecting runtime failures.
 * Asserts that 'x' expression is true. If not - records place of calling
 * and performs a System Reset. Failing this assertion means some
 * crucial expression is violated and normal work can't be restored.
 */
#define ASSERT(x)	do { if (!x) assert(__FILE__, __LINE__); } while(0)


/**
 * @brief	Perform record into log that something suspicious detected.
 *
 * @param file	file in which something suspicious detected.
 * @param line	line of the file with a possible error.
 */
void warn(const char *file, uint32_t line);

/**
 * @brief	Function records its calling and do System Reset.
 *
 * @param file	file to record.
 * @param line	line to record.
 */
void assert(const char *file, uint32_t line);

#endif	// _ASSERT_H_

