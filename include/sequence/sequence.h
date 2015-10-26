#ifndef H_SEQUENCE
#define H_SEQUENCE

typedef struct sequence_struct * sequence;

sequence sequence_create(int start, int end, int diff);
void sequence_destroy(sequence);
unsigned int get_sequence_length(sequence);
void get_sequence_as_array(sequence, int[]);

#endif  /* H_SEQUENCE */
