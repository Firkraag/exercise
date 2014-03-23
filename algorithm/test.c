#include <stdio.h>

main() {
	int i;
	int s[20] = {10,15,8,2,1,6,3,16,13,4,5,20,9,11,7,19,18,12,14,17};
	int a[6] = {31,41,59,26,41,58};
	insertionsort(a, 6);
	for (i = 0; i < 6; i++) 
		printf("%d ", a[i]);
	printf("\n");
}
