#include <stdio.h>

/* Determine whether arguments can be added without overflow */
/* This function should return 1 if arguments x and y can be added without causing overflow */
int uadd_ok(unsigned x, unsigned y) {
	unsigned sum = x + y;
	
	return sum >= x;
}

//main() {
	//unsigned int x = 0xffffffff;
	//unsigned int y = 0u; //0xffffffff;
//
	//printf("%d\n", uadd_ok(x, y));
//}
