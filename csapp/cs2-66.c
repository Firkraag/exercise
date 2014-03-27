#include <stdio.h>

//Generate mask indicating leftmost 1 in x. Assume w=32. For example 0xFF00 -> 0x8000, and 0x6600 --> 0x4000. If x = 0, then return 0.
int rightmost_one(unsigned x) {
//	int y = -((int) x);

//	printf("0x%x, 0x%x, 0x%x\n", y, x,  y & x);
	return -x & x;
}


main() {
	printf("0x%x, 0x%x, 0x%x\n", rightmost_one(0xfffffff0), rightmost_one(0x6600), rightmost_one(0x8000));
}
	
