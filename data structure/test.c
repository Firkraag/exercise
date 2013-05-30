#include <stdio.h>
#define element_type int
typedef struct node *node_ptr;
struct node {
        element_type element;
        node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;
position find(element_type x, LIST L) {
	position p;
	p = L->next;
	while (p != NULL && p->element != x)
		p = p->next;
	return p;
}
position find_previous(element_type x, LIST L) {
	position p;
	p = L;
	while ((p->next != NULL && p->next->element != x)
		p = p->next;
	return p;
}
main() {
	//int a[1] = {1};
//	unsigned m = 10, n = 20;
//	printf("%u\n", gcd(m, n));
	//printf("%d\n", max_subsequence_sum4(a,1));
//	printf("%d\n", pow1(2,8));
	relative_prime_rate(100);
}
