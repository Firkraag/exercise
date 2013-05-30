#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
struct queue_record {
	unsigned q_max_size;	/* Maximum # of elements */
	/* until Q is full */
	unsigned q_front;
	unsigned q_rear;
	unsigned q_size;
	element_type *q_array;
};
typedef struct queue_record *QUEUE;
int is_empty(QUEUE);
void make_null(QUEUE);
