/* Some routines are copied from date structures and algorithm analysis in C.
 * Assume use of a header node. */

#include "linked_list.h"

int is_empty(LIST L) {
	return L->next == NULL;
}
int is_last(position p, LIST L) {
	return p->next == NULL;
}
/* Return position of x in L; NULL if not found */
position find(element_type x, LIST L) {
	position p = L->next;
	while (p != NULL) {
		if (p->element == x)
			break;
		else 
			p = p->next;
	}
	return p;
}
/* Only delete the first occurence of x and does nothing if x is not in the list. Cell pointed to by p->next is wiped out.
 * Assume that the position is legal. Assume use of a header node. */
void delete(element_type x, LIST L) {
	position p = find_previous(x, L);
	position tmp_cell;

	if (p->next != NULL)
		tmp_cell = p->next;
		p->next = tmp_cell->next;
		free(tmp_cell);
}

/* Return position of the node before x. Uses a header. If element is not found, then next field of returned value is NULL */
position find_previous(element_type x, LIST L) {
	position p = L;

	while (p->next != NULL) {
		if ((p->next)->element == x)
			break;
		else 
			p = p->next;
	}
	return p;
}

/* Insert (after legal position p). Header implementation assumed, */
void insert(element_type x, LIST L, position p) {
	position tmp_cell = (position) malloc(sizeof(struct node));
	
	if (tmp_cell == NULL)
		printf("Out of space! ! !");
	else {
		tmp_cell->next = p->next;
		tmp_cell->element = x;
		p->next = tmp_cell;
	}
}

void print_list(LIST L) {
	position p;

	for (p = L->next; p != NULL; p = p->next)
		printf("%d ", p->element);
	printf("\n");
}
/* find the kth in list L, return pointer to it */
position kth(LIST L, int k) {
	int i;
	position p = L;

	for (i = 0; i < k; i++) {
    	p = p->next;
  	}
  	return p;
}
/* All the other cells are freed, only the header is remained */
void delete_list(LIST L) {
	position p, tmp;

	p = L->next;
	L->next = NULL;
	while (p != NULL) {
		tmp = p;
		p = tmp->next;
		free(tmp);
	}
}

