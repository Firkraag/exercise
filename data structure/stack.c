typedef struct node *node_ptr;
struct node {
	element_type element;
	node_ptr next;
};
typedef node_ptr STACK;
/* Stack implemention will use a header. */
int is_empty(STACK S) {
	return S->next == NULL;
}
STACK create_stack(void) {
	STACK S;
	S = (STACK) malloc(sizeof(struct node));
	if (S == NULL)
		fatal_error("Out of space!!!");
	return S;
}
void make_null(STACK S) {
	if (S != NULL)
		S->next = NULL;
	else 
		error("Must use create_stack first");
}
void push(element_type x, STACK S) {
	node_ptr tmp_cell;
	tmp_cell = (node_ptr) malloc(sizeof(struct node));
	if (tmp_cell == NULL)
		fatal_error("Out of space!!!");
	else {
		tmp_cell->element = x;
		tmp_cell->next = S->next;
		S->next = tmp_cell;
	}
}
element_type top(STACK S) {
	if (S->next == NULL)
		error("Empty stack");
	else
		return S->next->element;
}
void pop(STACK S) {
	node_ptr first_cell;
	if (S->next == NULL)
		error("Empty stack");
	else {
		first_cell = S->next;
		S->next = first_cell->next;
		free(first_cell);
	}
}
