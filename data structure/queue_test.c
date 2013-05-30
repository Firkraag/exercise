#include "queue_linked_list.h"


void create(int n, q_ptr Q) {
	int i;

	Q->header = (node_ptr) malloc(sizeof(struct node));
	Q->rear = Q->header;

	for (i = 1; i <= n; i++)
	{
		Q->rear->next = (node_ptr) malloc(sizeof(struct node));
		Q->rear->next->element = i;
		Q->rear = Q->rear->next;
	}
	Q->rear->next = NULL;
}

void print_queue(struct QUEUE Q) {
	node_ptr p;

	for (p = Q.header->next; p != NULL; p = p->next)
		printf("%d ", p->element);
	printf("\n");
}

main() {
	struct QUEUE Q;

	create(10, &Q);
	printf("%d\n", Q.rear->element);
	print_queue(Q);
	dequeue(&Q);
	print_queue(Q);
	dequeue(&Q);
	print_queue(Q);
	enqueue(20, &Q);
	print_queue(Q);
}

