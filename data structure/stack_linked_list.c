#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
typedef struct node *node_ptr;
struct node {
	element_type element;
	node_ptr next;
};

typedef node_ptr STACK;

int is_empty(STACK S) {
	return S->next == NULL;
}

STACK create_stack(void) {
	STACK S;
	
	S = (STACK) malloc(sizeof(struct node));
	if (S == NULL)
		printf("Out of space !!!");
	return S;
}

void make_null(STACK S) {
	if (S != NULL)
		S->next = NULL;
	else
		printf("Must use create_stack first");
}
void push(element_type x, STACK S) {
	node_ptr tmp_cell = (node_ptr) malloc(sizeof(struct node));

	if (tmp_cell == NULL)
		printf("Out of space !!!");
	else {
		tmp_cell->next = S->next;
		tmp_cell->element = x;
		S->next = tmp_cell;
	}
}
element_type top(STACK S) {
	if (is_empty(S))
		printf("Empty Stack");
	else
		return S->next->element;
}
void pop(STACK S) {
	node_ptr first_cell;

	if (is_empty(S))
		printf("Empty stack");
	else
	{
		first_cell = S->next;
		S->next = first_cell->next;
		free(first_cell);
	}
}
