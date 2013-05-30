#include <stdio.h>
#define MAX 5
void print(int *a, int n) {
}
void radixsort(int *a, int n) {
	int i, b[MAX], m = a[0], exp = 1;
	for (i = 0; i < n; i++) {
		if (a[i] > m)
			m = a[i];
	}
	printf("%d\n", m);
	while (m / exp > 0) {
		int bucket[10] = {0};
		for (i = 0; i < n; i++) 
			bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++) 
			bucket[i]  += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];	
		exp *= 10;
	}
	for (i = 0; i < n; i++) 
		printf("%d ", a[i]);

}

main() {
	int a[] = {170,45,75,90,802,24,2,66};
	radixsort(a, 8);
}
