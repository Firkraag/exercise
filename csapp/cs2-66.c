#include <stdio.h>

int rightmost_one(unsigned x) {
	return -x & x;
}
int rightmost_zero(unsigned x) {
	return rightmost_one(~x);
}

//Generate mask indicating leftmost 1 in x. Assume w=32. For example 0xFF00 -> 0x8000, and 0x6600 --> 0x4000. If x = 0, then return 0.
int leftmost_one(unsigned x) {
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;

	//The following statement is not working for x = 0
	//return (x >> 1) + 1;
	//The following statement is not working for x = 0xffffffff
	//return (x + 1) >> 1;
	x -= (x >> 1);
	return x;
}
int leftmost_zero(unsigned x) {
	return leftmost_one(~x);
}	
	
main() {
	//printf("0x%x, 0x%x, 0x%x\n", rightmost_one(0xfffffff0), rightmost_one(0x6600), rightmost_one(0x8000));
	//printf("0x%x\n", 1 << 17);
	//printf("0x%x\n", 0xff99 ^ 0xff96);
	//printf("0x%x\n", (0x1 << 24) - 1);
	//printf("0x%x\n", leftmost_one(0x03000000));
	printf("0x%x, 0x%x\n", leftmost_zero(0xffffff00), rightmost_zero(0xff));
}
