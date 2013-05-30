#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
typedef struct node *node_ptr;
struct node {
	element_type element;
	node_ptr next;
};
struct QUEUE {
	node_ptr header;
	node_ptr rear;
};
typedef struct QUEUE *q_ptr;
int is_empty(q_ptr);
q_ptr create_queue(void);
void make_null(q_ptr);
void enqueue(element_type x, q_ptr);
element_type top(q_ptr);
void dequeue(q_ptr);

