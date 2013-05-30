#include <stdio.h>
#include <stdlib.h>
#define MIN_STACK_SIZE 100
typedef char element_type;
struct stack_record {
	int stack_size;
	int top_of_stack;
	element_type *stack_array;
};

typedef struct stack_record *STACK;
#define EMPTY_TOS -1	/*	Signifies an empty stack */
STACK create_stack(unsigned);
void dispose_stack(STACK);
int is_empty(STACK);
int is_full(STACK);
void push(element_type, STACK);
element_type top(STACK);
element_type pop(STACK);
