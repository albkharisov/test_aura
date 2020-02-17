#include "unity.h"
#include <limits.h>
#include "incr.h"
#include "mock_assert.h"

void setUp(void)
{
	number_maxval_set(0);
	number_maxval_set(INT_MAX);
}

void tearDown(void)
{
	// intentionally empty
}

void test_initValueIsZero(void)
{
	int number = number_get();
	TEST_ASSERT_EQUAL_INT(number, 0);
}

void test_numbergetFunctionAndIncrement(void)
{
	for (int i = 0; i < 42; ++i) {
		TEST_ASSERT_EQUAL_INT((int) i, number_get());
		number_inc();
	}
}

void test_maxvalFunctionSetsupThreshold(void)
{
	number_maxval_set(42);
	for (int i = 0; i < (42*2+2); ++i) {
		TEST_ASSERT_EQUAL_INT(i % 42, number_get());
		number_inc();
	}
}

void test_maxvalFunctionClearsNumberValue(void)
{
	number_maxval_set(43);
	for (int i = 0; i < 42; ++i)
		number_inc();

	TEST_ASSERT_EQUAL_INT(42, number_get());
	number_maxval_set(42);
	TEST_ASSERT_EQUAL_INT(0, number_get());
}

void test_incrementRestoresFunctionalityAfterRestoringThreshold(void)
{
	number_maxval_set(0);
	TEST_ASSERT_EQUAL_INT(0, number_get());
	number_inc();
	TEST_ASSERT_EQUAL_INT(0, number_get());
	number_maxval_set(INT_MAX);
	TEST_ASSERT_EQUAL_INT(0, number_get());
	number_inc();
	TEST_ASSERT_EQUAL_INT(1, number_get());
	number_inc();
	TEST_ASSERT_EQUAL_INT(2, number_get());
}

void test_maxvalBorderConditions(void)
{
	int number = number_get();
	warn_Expect("src/incr.c", 77);
	warn_IgnoreArg_line();
	number_maxval_set(-1);

	number_maxval_set(0);
	TEST_ASSERT_EQUAL_INT(0, number_get());
	number_maxval_set(1);
	TEST_ASSERT_EQUAL_INT(0, number_get());
	number_maxval_set(INT_MAX);
	TEST_ASSERT_EQUAL_INT(0, number_get());
}

