#include <stdio.h>
#include <limits.h>

int main() {
	int x = 1;
	int y = INT_MAX;
	int z = -INT_MAX;
	double dx = (double) x;
	double dy = (double) y;
	double dz = (double) z;

	printf("%g, %d\n", dx, (float) x == (float) dx);
	printf("%g, %g\n", dx - dy, (double) (x - y));
	printf("%g, %g\n", (dx + dy) + dz, dx + (dy + dz));
}
