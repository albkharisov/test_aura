#include "unity.h"
#include <limits.h>
#include "incr.h"
#include "mock_assert.h"

void setUp(void)
{
	numberMaxvalSet(0);		// reset number value
	numberMaxvalSet(INT_MAX);
}

void tearDown(void)
{
	// intentionally empty
}

void test_initValueIsZero(void)
{
	int number = numberGet();
	TEST_ASSERT_EQUAL_INT(number, 0);
}

void test_numbergetFunctionAndIncrement(void)
{
	for (int i = 0; i < 42; ++i) {
		TEST_ASSERT_EQUAL_INT((int) i, numberGet());
		numberInc();
	}
}

void test_maxvalFunctionSetsupThreshold(void)
{
	numberMaxvalSet(42);
	for (int i = 0; i < (42*2+2); ++i) {
		TEST_ASSERT_EQUAL_INT(i % 42, numberGet());
		numberInc();
	}
}

void test_maxvalFunctionClearsNumberValue(void)
{
	numberMaxvalSet(43);
	for (int i = 0; i < 42; ++i)
		numberInc();

	TEST_ASSERT_EQUAL_INT(42, numberGet());
	numberMaxvalSet(42);
	TEST_ASSERT_EQUAL_INT(0, numberGet());
}

void test_incrementRestoresFunctionalityAfterRestoringThreshold(void)
{
	numberMaxvalSet(0);
	TEST_ASSERT_EQUAL_INT(0, numberGet());
	numberInc();
	TEST_ASSERT_EQUAL_INT(0, numberGet());
	numberMaxvalSet(INT_MAX);
	TEST_ASSERT_EQUAL_INT(0, numberGet());
	numberInc();
	TEST_ASSERT_EQUAL_INT(1, numberGet());
	numberInc();
	TEST_ASSERT_EQUAL_INT(2, numberGet());
}

void test_maxvalNegativeThreshold(void)
{
	int number = numberGet();
	warn_Expect("src/incr.c", 40);
	warn_IgnoreArg_line();
	numberMaxvalSet(-1);
}

