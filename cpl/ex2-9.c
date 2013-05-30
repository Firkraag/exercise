#include <stdio.h>
/* bitcount: count 1 bits in x, a faster version */
int bitcount(unsigned x) {
	int b;
	
	for (b = 0; x != 0; x &= (x - 1))	// x &= (x-1) deletes the rightmost 1-bit in x
		b++;
	return b;
}
main() {
	printf("%d\n", bitcount(0x10111001));
}
