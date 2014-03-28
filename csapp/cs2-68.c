#include <stdio.h>
/* Clear all but least significant n bits of x 
Examples: x = 0x78ABCDEF, n = 8 --> 0xEF, n = 16 --> 0xCDEF
Assume 1 <= n <= w */

int lower_bits(int x, int n) {
	int mask = (1 << n) - 1;
	return mask & x;
}
//main() {
	//printf("0x%x\n", lower_bits(0x12345678, 10));
//}
