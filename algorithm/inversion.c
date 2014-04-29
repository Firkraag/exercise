// This program determines the number of inversions in 
// any permution on n elements
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

	// MERGE(A, p, q, r)
	// n1 = q - p + 1
	// n2 = r - q
	// L[1...n1] = A[p...q]
	// R[1...n2] = A[q+1...r]
	// L[n1+1] = ∞
	// R[n2+1] = ∞
	// i = 1
	// j = 1
	// for k = p to r
	// if L[i] <= R[j]
	// A[k] = L[i]
	// i = i + 1
	// else
	// A[k] = R[j]
	// j = j + 1
static int invs = 0;

void MERGE(int A[], int first, int inter, int end)
{
	int len1 = inter - first + 1;
	int len2 = end - inter;
	int i;
	int j;
	int k;
	int *L;
	int *R;

	L = (int *)calloc(len1 + 1, sizeof(int));
	R = (int *)calloc(len2 + 1, sizeof(int));
	for (i = 0; i < len1; i++)
		L[i] = A[first + i];
	for (j = 0; j < len2; j++)
		R[j] = A[inter + j + 1];
	L[len1] = INT_MAX;
	R[len2] = INT_MAX;

	i = 0;
	j = 0;
	for (k = first; k <= end; k++)
	{
		if (L[i] <= R[j])
			A[k] = L[i++];
		else {
			A[k] = R[j++];
			printf("%d, %d, %d\n", invs, inter, i);
			invs = invs + len1 - i;
			printf("%d, %d\n", invs, L[i]);
		}

	}
	free(L);
	free(R);
}

void MergeSort(int A[], int first, int end)
{
	if (first < end)
	{
		int middle = (first + end) / 2;

		MergeSort(A, first, middle);
		MergeSort(A, middle + 1, end);
		MERGE(A, first, middle, end);
	}
}

int main()
{
	int a[100];
	int i;
	// int a[2] = {4,3};
	// int a[3] = {4, 3, 1};
//	MERGE(a, 3, 5, 7);
   for (i = 0; i < 100; i++ )
       a[i] = 100 - i;
    MergeSort(a, 0, 99);
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4],
		   a[5], a[6], a[7], invs);
	return 0;
}
