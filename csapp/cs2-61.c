#include <stdio.h>

int any_bit_equals_1(int x) {
	return !!(x ^ 0);
}

int any_bit_equals_0(int x) {
	return !!(x ^ (~0));
}

//any bit in the most significant byte of x equals 1, return 1; otherwise return 0
int any_bit_in_msb_equals_1(int x) {
	return !!(x & (0xff << ((sizeof(int) - 1) << 3)));
}
//any bit in the least significant byte of x equals 0, return 1; otherwise return 1
int any_bit_in_lsb_equals_0(int x) {
	int shift_val = (sizeof(int) - 1) << 3;
	int lsb = ((x << shift_val) >> shift_val) & 0xff;
	
	return !!(lsb ^ 0xff);
}

//int main() {
	//int i;
//
	//for (i = 0; i < 300; i++) {
		//printf("%d\n", any_bit_equals_1(i));
		//printf("%d\n", any_bit_equals_0(i));
		//printf("%d, %d\n",i,  any_bit_in_lsb_equals_0(i));
	//}
	//printf("%d\n", any_bit_equals_0(~0));
	//printf("%x, %x\n", any_bit_in_lsb_equals_0(0xffffffff), any_bit_in_lsb_equals_0(0xffffff01));
	//printf("%d, %d\n", any_bit_in_msb_equals_1(0xffffffff), any_bit_in_msb_equals_1(0x01ffffff));
//
//}
