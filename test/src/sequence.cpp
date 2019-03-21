#include "CppUTest/TestHarness.h"

extern "C"
{
#include "sequence.h"
}

TEST_GROUP(SEQUENCE)
{
	sequence A;

	void setup()
	{
		/**
		 * The arguments "1, 16, 1" means: 1 to 16 with difference of 1
		 * i.e, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}
		 */
		A = sequence_create(1, 16, 1);
		CHECK(NULL != A);
	}

	void teardown()
	{
		sequence_destroy(A);
	}

};

TEST(SEQUENCE, length_of_sequence)
{
	LONGS_EQUAL(16, get_sequence_length(A));
}

TEST(SEQUENCE, return_array_for_given_sequence)
{
	int i;
	int res[16];

	get_sequence_as_array(A, res);
	for (i = 0; i < 16; i++)
	{
		LONGS_EQUAL(i+1, res[i]);
	}
}

