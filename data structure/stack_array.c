#include "stack_array.h"

STACK create_stack(unsigned max_elements) {
	STACK S;
	if (max_elements < MIN_STACK_SIZE)
		printf("Stack size is too small");
	S = (STACK) malloc(sizeof(struct stack_record));
	if (S == NULL)
		printf("Out of space!!!");
	S->stack_array = (element_type *) malloc(sizeof(element_type) * max_elements);
	if (S->stack_array == NULL)
		printf("Out of space!!!");
	S->top_of_stack = EMPTY_TOS;
	S->stack_size = max_elements;
	return S;
}
void dispose_stack(STACK S) {
	if (S != NULL) {
		free(S->stack_array);
		free(S);
	}
}
int is_empty(STACK S) {
	return S->top_of_stack == EMPTY_TOS;
}
int is_full(STACK S) {
	return S->top_of_stack >=  S->stack_size;
}
void push(element_type x, STACK S) {
	if (is_full(S))
		printf("Full stack");
	else
		S->stack_array[++S->top_of_stack] = x;
}

element_type top(STACK S) {
	if (is_empty(S))
		printf("Empty stack");
	else
		return S->stack_array[S->top_of_stack];
}
element_type pop(STACK S) {
	if (is_empty(S))
		printf("Empty stack");
	else
		return S->stack_array[S->top_of_stack--];
}
