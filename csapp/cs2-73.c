#include <stdio.h>
#include <limits.h>
/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y) {
	int sum = x + y;
	int neg_over = (x < 0 && y < 0 && sum >= 0);
	int pos_over = (x >= 0 && y >= 0 && sum < 0);
	
	if (neg_over)
		sum = INT_MIN;
	else if (pos_over)
		sum = INT_MAX;
	return sum;
}

int main() {
	printf("%d, %d, %d\n", INT_MIN - 1, INT_MAX + 1, saturating_add(100, 100));
}
