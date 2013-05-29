#include <stdio.h>

int shift_left2_rightn(int x, int n) {
	x <<= 2;
	x >>= n;
	return x;
}
main() {
	printf("%x\n", shift_left2_rightn(0xffffffff, 4));
}
