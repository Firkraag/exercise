#include <stdio.h>
/* Do rotating right shift. Assume 0 <= n < w
Examples when x = 0x12345678 and w = 32;
	n = 4 -> 0x81234567, n = 20 -> 0x45678123
*/
unsigned rotate_right(unsigned x, int n) {
	unsigned y = x >> n;
	x = x << (32 - n);
	return x | y;
}
main() {
	printf("%x\n", rotate_right(0x12345678, 4));
}
