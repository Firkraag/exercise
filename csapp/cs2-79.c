#include <stdio.h>

int threefourths(int x) {
	return x -((x < 0 ? x : (x +(1 << 2) - 1)) >> 2);
}

int main() {
	int i;

	for (i = - 100; i <= 100; i++)
		printf("3 * %d / 4 = %d\n", i, threefourths(i));
}
