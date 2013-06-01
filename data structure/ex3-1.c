#include "linked_list.h"

void print_list(LIST L) {
	position p;

	for (p = L->next; p != NULL; p = p->next)
		printf("%d ", p->element);
	printf("\n");
}

