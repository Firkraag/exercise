#include "linked_list.h"

LIST create(int n) {
	position ret = (position) malloc(sizeof(struct node));
	position p = ret;
	int i;

	for (i = 1; i <= n; i++)
	{
		p->next = (position) malloc(sizeof(struct node));
		p->next->element = i;
		p = p->next;
	}
	p->next = NULL;
	return ret;

}

void print_list(LIST L) {
	position p;

	for (p = L->next; p != NULL; p = p->next)
		printf("%d ", p->element);
	printf("\n");
}
void print_lots(LIST L, LIST P) {
	position p, ptr;

	for (p = P->next; p != NULL; p = p->next) {
		ptr = kth(L, p->element);
		printf("%d\n", ptr->element);
	}
}
main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	position p;
	LIST L, P;
//	printf("%d\n", binsearch(10, a, 10));
	L =	create(10);	
	P = create(6);
/*	p = find(9, L);
	if (p->next == NULL)
		printf("end");
	printf("%d\n", is_last(p, L));
	print_list(L);
	delete(3,L);
	print_list(L);
	insert(15, L, p);	
	print_list(L);		
*/
	print_lots(L, P);
	delete_list(L);
	printf("%d\n", is_empty(L)+1);
}
