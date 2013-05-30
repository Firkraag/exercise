#include "queue_linked_list.h"
int is_empty(q_ptr Q) {
	return Q->header->next == NULL;
}

q_ptr create_queue(void) {
	q_ptr queue;

	queue->header = (struct node *) malloc(sizeof(struct node));
	queue->rear = queue->header;
	if (queue->header == NULL)
		printf("Out of space !!!");
	return queue;
}

void make_null(q_ptr Q) {
	if (Q->header != NULL)
		Q->header->next = NULL;
	else
		printf("Must use create_queue first");
}
	
void enqueue(element_type x, q_ptr Q) {
	node_ptr tmp_cell = (node_ptr) malloc(sizeof(struct node));
	
	if (tmp_cell == NULL)
		printf("Out of space !!!");
	else {
		tmp_cell->next = NULL;
		tmp_cell->element = x;
		Q->rear->next = tmp_cell;
	}
}
element_type top(q_ptr Q) {
	if (is_empty(Q))
		printf("Empty Qtack");
	else
		return Q->header->next->element;
}
void dequeue(q_ptr Q) {
	node_ptr first_cell;

	if (is_empty(Q))
		printf("Empty stack");
	else
	{
		first_cell = Q->header->next;
		Q->header->next = first_cell->next;
		free(first_cell);
	}
}
