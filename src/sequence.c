/**
 * At present only Arithmetic Progression supported
 */

#include "sequence.h"
#include <stdlib.h> /* malloc() and free() */

#define COUNT(start, end, diff)  (((end - start) / diff) + 1)

typedef struct sequence_struct
{
	int start;
	int end;
	int diff;
} sequence_struct;

sequence sequence_create(int start, int end, int diff)
{
	sequence self;

	/* TODO add: cases for (start < end and diff +ve) along with 
	 * (start > end and diff -ve) condition and test cases.
	 * Currently only positive growing sequences are present.
	 */
	if ((start < end) && (diff > 0))
	{
		self = malloc(sizeof(sequence_struct));
		self->start = start;
		self->end = end;
		self->diff = diff;
	}
	else  /* TODO: test cases with check return value NULL */
	{
		return NULL;
	}
	return self;
}

void sequence_destroy(sequence self)
{
	free(self);
}

unsigned int get_sequence_length(sequence self)
{
	return (unsigned int) COUNT( self->start, self->end, self->diff );
}

void get_sequence_as_array(sequence self, int res[])
{
	int i;
	/* TODO check valid object? "self" */
	unsigned int count = COUNT( self->start, self->end, self->diff );
	for(i = 0; i < count; i++)
	{
		res[i] = self->start + ( i * self->diff );
	}
}
