#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int, int v[], int);
main() {
	int v[10]={1,2,3,4,5,6,7,8,9,10};
	int x = 4;
	int i;
	for (i = -5;i <= 15;i++)
		printf("%d\n", binsearch(i,v,10));
}
int binsearch(int x, int v[], int n) {
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high)  {
		mid = (high + low)/2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
} 
