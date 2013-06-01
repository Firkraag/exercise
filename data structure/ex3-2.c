#include "linked_list.h"

void print_lots(LIST L, LIST P) {
	position p, ptr;

	for (p = P->next; p != NULL; p = p->next) {
		ptr = kth(L, p->element);
		printf("%d\n", ptr->element);
	}
}
