#include <stdio.h>
#define SPACE_SIZE 100
typedef char element_type;
typedef unsigned node_ptr;
struct node {
	element_type element;
	node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;
struct node CURSOR_SPACE[SPACE_SIZE];

void init(struct node s[], int n) {
	int i;

	for (i = 0; i < n - 1; i++) 
		s[i].next = i + 1;
	s[n - 1].next = 0;
	for (i = 1; i < n; i++)
		s[i].element = 2 * i;
	
}
/* the header of the linked list is s[header] */
void print(struct node s[], position header) {
	int i;

	for (i = s[header].next; i != 0; i = s[i].next)
		printf("%c ", s[i].element);
	putchar('\n');	
}
position cursor_alloc(void) {
	position p;

	p = CURSOR_SPACE[0].next;
	CURSOR_SPACE[0].next = CURSOR_SPACE[p].next;
	return p;
}

void cursor_free(position p) {
	CURSOR_SPACE[p].next = CURSOR_SPACE[0].next;
	CURSOR_SPACE[0].next = p;
}

int is_empty(LIST L) /* using a header node */
{
	return CURSOR_SPACE[L].next == 0
}
int is_last(position p, LIST L) /* using a header node */
{
	return	CURSOR_SPACE[p].next == 0;
}
position find(element_type x, LIST L) /* using a header node */
{
	position p = CURSOR_SPACE[L].next;

	while (p != 0) {
		if (CURSOR_SPACE[p].element == x)
			break;
		else
			p = CURSOR_SPACE[p].next;
	}
	return p;
}
position find_previous(element_type x, LIST L) {
	position p = L;

	while (CURSOR_SPACE[p].next != NULL) {
		if (CURSOR_SPACE[CURSOR_SPACE[p].next].element == x)
			break;
		else
			p = CURSOR_SPACE[p].next;
	}
	return p;
}

void delete(element_type x, LIST L) {
	position p = find_previous(x, L):
	position tmp_cell;

	if (CURSOR_SPACE[p].next != 0) {
		tmp_cell = CURSOR_SPACE[p].next;
		CURSOR_SPACE[p].next = CURSOR_SPACE[tmp_cell].next;
		cursor_free(tmp_cell);
	}
}
/* Insert (after legal position p); */
/* header implementation assumed */
void insert(element_type x, LIST L, position p) {
	position tmp_cell = cursor_alloc();
	
	if (tmp_cell == 0)
		printf("Out of space!!!");
	else {
		CURSOR_SPACE[tmp_cell].next = CURSOR_SPACE[p].next;
		CURSOR_SPACE[tmp_cell].element = x;
		CURSOR_SPACE[p].next = tmp_cell;
	}
}
	
main() {
	struct node s[10], b[11];

	b[0].next = 6;
	b[1].element =  'b';
	b[1].next = 9;
	b[2].element = 'f';
	b[2].next = 0;
	b[3].next = 7;
	b[4].next = 0;
	b[5].next = 10;
	b[6].next = 4;
	b[7].element = 'c';
	b[7].next = 8;
	b[8].element = 'd';
	b[8].next = 2;
	b[9].element = 'e';
	b[9].next = 0;
	b[10].element = 'a';
	b[10].next = 1;

	print(b, 3);
	print(b, 5);
}
