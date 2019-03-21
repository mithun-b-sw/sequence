/**
 * This test suite contain STRICT test cases for Sequence module.
 *
 * Note: in case of test failure the last function call sequence_destroy()
 *       will not run in failed tests cases.
 *       Further sequence_destroy() call after the failed create (malloc)
 *       should not fail, since calling free(NULL) will not do any thing.
 *
 * TODO add test case for get_sequence_length() without creating sequence.
 * TODO add test case, sequence_create() will create zero number of elements.
 * TODO add test case for malloc() fail.
 */

#include "CppUTest/TestHarness.h"

extern "C"
{
#include "sequence.h"
}

TEST_GROUP(SEQUENCE_STRICT)
{

};

TEST(SEQUENCE_STRICT, sequence_from_negative_to_positive_range_with_incrementing_numbers)
{
	sequence A = NULL;
	A = sequence_create(-14, 16, 1);
	CHECK(NULL != A); /* Tests Create if succeed */
	sequence_destroy(A);
	/* If A is not NULL, sequence_destroy(A) try to free memory allocation */
}

TEST(SEQUENCE_STRICT, sequence_from_positive_to_negative_range_with_decrementing_numbers)
{
	sequence A = NULL;
	A = sequence_create(14, -6, -1);
	CHECK(NULL != A);
	sequence_destroy(A);
}

TEST(SEQUENCE_STRICT, sequence_from_negative_to_positive_range_with_decrementing_numbers)
{
	sequence A = NULL;
	A = sequence_create(-14, 60, -2);
	CHECK(NULL == A); /* Tests Create if fails */
	sequence_destroy(A);
	/* If A is NULL, no harm in calling sequence_destroy(A) */
}

TEST(SEQUENCE_STRICT, sequence_from_positive_to_negative_range_with_incrementing_numbers)
{
	sequence A = NULL;
	A = sequence_create(15, -6, 3);
	CHECK(NULL == A);
	sequence_destroy(A);
}

/* TODO Repeat above 4 cases start/end sequence with +ve/+ve and -ve/-ve numbers */

TEST(SEQUENCE_STRICT, length_of_sequence_without_exact_ending)
{
	int expected_sequence[] = {15, 11, 7, 3, -1, -5};
	size_t expected_size = (sizeof expected_sequence) / (sizeof (int));
	int resultant_sequence[expected_size] = {};
	sequence A = NULL;
	size_t i = 0;

	A = sequence_create(15, -6, -4);
	CHECK(NULL != A);

	LONGS_EQUAL(expected_size, get_sequence_length(A));

	get_sequence_as_array(A, resultant_sequence);
	for (i = 0; i < expected_size; i++)
	{
		LONGS_EQUAL(expected_sequence[i], resultant_sequence[i]);
	}

	sequence_destroy(A);
}

TEST(SEQUENCE_STRICT, sequence_creation_attempt_with_zero_increment)
{
	sequence A = NULL;
	A = sequence_create(15, -6, 0);
	CHECK(NULL == A);
	sequence_destroy(A);
}

TEST(SEQUENCE_STRICT, sequence_get_array_attempt_without_sequence_creation)
{
	sequence A = NULL;
	int * result_array = NULL;

	get_sequence_as_array(A, result_array);
	sequence_destroy(A);
}
