#include <stdio.h>
#include <limits.h>

struct value {
        int low;
        int high;
        int sum;
};

//A brute-force solution to find maximum subarray: just try every possible pair
struct value FIND_MAXIMUM_SUBARRAY(int A[], int low, int high) {
	int i, j;
	int left, right;
	int sum;
	int max_sum = INT_MIN;
	struct value max;

	for (i = low; i <=high; i++) {
		sum = 0;
		for (j = i; j <= high; j++) {
			sum = sum + A[j];
			if (sum >= max_sum) {
				left = i;
				right = j;
				max_sum = sum;
			}
		}
	}
	max.low = left;
	max.high = right;
	max.sum = max_sum;
	return max;
}

int main() {
        int a[17] = { 13, -3, -25, 20, -3, -16, 23, 18, 20, -7, 12, -5, -22, -15, -4, 7, 0};
        struct value max;

        max = FIND_MAXIMUM_SUBARRAY(a, 0, 16);
        printf("%d, %d, %d, %d, %d\n", max.low, max.high, max.sum, a[max.low], a[max.high]);
}

