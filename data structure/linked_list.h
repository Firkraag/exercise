/* Some are copied from date structures and algorithm analysis in C */

#include <stdio.h>
#include <stdlib.h>


typedef struct node *node_ptr;
typedef int element_type;
struct node {
	element_type element;
	node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;

int is_empty(LIST);
int is_last(position, LIST);
position find(element_type, LIST);
void delete(element_type, LIST);
position find_previous(element_type, LIST);
void insert(element_type, LIST, position);
position kth(LIST, int);
void print_list(LIST)

