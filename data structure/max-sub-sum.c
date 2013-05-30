#include <stdio.h>
int max_subsequence_sum(int a[], unsigned int n) {
	int this_sum, max_sum, best_i, best_j, i, j, k;
	
	max_sum = 0;
	best_i = best_j = -1;
	
	for (i=0;i<n;i++)
		for (j = i; j < n; j++) {
			this_sum = 0;
			for (k = i; k <= j;k++)
				this_sum += a[k];
			if (this_sum > max_sum) {
				max_sum = this_sum;
				best_i = i;
				best_j = j;
			}
		}
	return max_sum;
}
int max_subsequence_sum2(int a[], unsigned int n) {
	int this_sum, max_sum, best_i, best_j, i, j, k;
	
	max_sum = 0; best_i = best_j = -1;
	for (i=0; i < n; i++)  {
		this_sum = 0;
		for (j = i; j < n; j++) {
			this_sum += a[j];
		    if (this_sum > max_sum) {
				max_sum = this_sum;
				best_i = i;
				best_j = j;
			}
		}
	}
	return max_sum;
}
int max3(int a, int b, int c) {
	if (a > b) {
		if (a > c)
			return a;
		else 
			return c;
	}
	else if (b > c) 
		return b;
	else 
		return c;
}
int max_sub_sum(int a[], int left, int right) {
	int max_left_sum, max_right_sum;
	int max_left_border_sum, max_right_border_sum;
	int left_border_sum, right_border_sum;
	int center, i;

	if (left == right) {	/* Base Case */
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	}
	center = (left + right) / 2;
	max_left_sum = max_sub_sum(a, left, center);
	max_right_sum = max_sub_sum(a, center+1, right);
	max_left_border_sum = 0; left_border_sum = 0;
	for (i=center; i>=left;i--) {
		left_border_sum += a[i];
		if (left_border_sum > max_left_border_sum)
			max_left_border_sum = left_border_sum;
	}
	max_right_border_sum = 0; right_border_sum = 0;
	for (i = center+1; i <= right; i++) {
		right_border_sum += a[i];
		if (right_border_sum > max_right_border_sum)
			max_right_border_sum = right_border_sum;
	} 
	return max3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
}
int max_subsequence_sum3(int a[], unsigned int n) {
	return max_sub_sum(a, 0 , n-1);
}
int max_subsequence_sum4(int a[], unsigned int n) {
	int this_sum, max_sum, best_i, best_j, i, j;
	
	i = this_sum = max_sum = 0; best_i = best_j = -1;

	for (j=0; j < n; j++) {
		this_sum += a[j];
		if (this_sum > max_sum) {
			max_sum = this_sum;
			best_i = i;
			best_j = j;
		}
		else if (this_sum < 0) {
			i = j + 1;
			this_sum = 0;	
		}
	}
//	printf("%d, %d, %d\n", best_i, best_j, max_sum);
	return max_sum;
}
