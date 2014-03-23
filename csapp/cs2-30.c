#include <stdio.h>
#include <limits.h>

int tadd_ok(int x, int y) {
	int sum = x + y;

	if ((x < 0 && y < 0 && sum >= 0) || (x > 0 && y > 0 && sum < 0))
		return 0;
	else
		return 1;
}

int main() {
	int x = INT_MIN;
	int y = INT_MIN;

	printf("%d\n", tadd_ok(x, y));
}
