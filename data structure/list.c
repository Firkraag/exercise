#include <stdio.h>
#define element_type int
typedef struct node *node_ptr;
struct node {
		element_type element;
		node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;

int is_empty(LIST L) {
		return L->next == NULL;
}
int is_last(position p, LIST L) {
		return p->next == NULL;
}
/* Return position of x in L; NULL if not found */
position find(element_type x, LIST L) {
		position p;
		p = L->next;
		while ((p != NULL) && (p->element != x))
				p = p->next;
		return p;
}
/* Uses a header. If element is not found, then next field */
/* of returned value is NULL */
position find_previous(element_type x, LIST L) {
		position p;
		p = L;
		while ((p->next != NULL) && (p->next->element != x))
			p = p->next;
		return p;
}
/* Delete from a list. Cell pointed */
/* to by p->next is wiped out. */
/* Assume that the position is legal. */
/* Assume use of a header node. */

void delete(element_type x, LIST L) {
	position p, tmp_cell;
	p = find_previous(x, L);
	if (p->next != NULL) {	/* Implicit assumption of header use */
		tmp_cell = p->next;
		p->next = tmp_cell->next;	/* bypass the cell to be deleted */
		free(tmp_cell);
	}
}
void print_list(L) {
	position p;
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->element);
		p = p->next;
	}
}
/* Insert (after legal position p). */
/* Header implementation assumed */
void insert(element_type x, LIST L, position p) {
	position tmp_cell;
	tmp_cell = (position) malloc(sizeof(struct node));
	if (tmp_cell == NULL)
		fatal_error("Out of space!!!");
	else {
		tmp_cell->element = x;
		tmp_cell->next = p->next;
		p->next = tmp_cell;
	}
}
void delete_list(LIST L) {
	position p, tmp_cell;
	p = L->next;
	L->next = NULL;
	while (p != NULL) {
		tmp_cell = p;
		p = p->next;
		free(tmp_cell);
	}
}
