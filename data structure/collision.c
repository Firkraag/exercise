#include <stdio.h>
#include <stdlib.h>
#define MIN_TABLE_SIZE 10

typedef int element_type;
typedef struct list_node *node_ptr;
struct list_node {
	element_type element;
	node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;

struct hash_tbl {
	unsigned table_size;
	LIST *the_lists;
};
typedef struct hash_tbl *HASH_TABLE;
HASH_TABLE initialize_table(unsigned table_size) {
	HASH_TABLE H;
	int i;

	if (table_size < MIN_TABLE_SIZE) {
		printf("Table size too small");
		return NULL;
	}
	H = (HASH_TABLE) malloc(sizeof(struct hash_tbl));
	if (H == NULL) {
		printf("Out of space! ! !");
	H->table_size = next_prime(table_size);
	H->the_lists = (position *) malloc(sizeof(LIST) * H->table_size);
	if (H->the_lists == NULL)
		printf("Out of space! ! !");
	for (i = 0; i < H->table_size; i++) {
		H->the_lists[i] = (LIST) malloc(sizeof(struct list_node));
		if (H->the_lists(i) == NULL)
			printf("Out of space! ! !");
		else
			H-
