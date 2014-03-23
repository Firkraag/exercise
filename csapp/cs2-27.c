#include <stdio.h>

/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y) {
	unsigned s = x + y;
	
	return s < x ? 0 : 1;
}

main() {
	unsigned int x = 0xffffffff;
	unsigned int y = 1u; //0xffffffff;

	printf("%d\n", uadd_ok(x, y));
}
