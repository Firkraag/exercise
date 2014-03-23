// implemention of algorithm merge sort


#include <limits.h>
void merge(int a[], int begin, int middle, int end) {
	int n1 = middle - begin + 1;
	int n2 = end - middle;
	int l[n1+1], r[n2+1];
	int i, j, k;

	for (i=0; i < n1; i++)
		l[i] = a[begin+i];
	for (j=0; j < n2; j++)
		r[j] = a[middle+j+1];
	l[n1] = INT_MAX;
	r[n2] = INT_MAX;
	i = 0, j = 0;
	for (k=begin; k <= end; k++) {
		if (l[i] <= r[j]) {
			a[k] = l[i];
			i++;
		}
		else {
			a[k] = r[j];
			j++;
		}
	}
}

void merge_sort(int a[], int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(a, start, middle);
		merge_sort(a, middle+1, end);
		merge(a, start, middle, end);
	}
}
