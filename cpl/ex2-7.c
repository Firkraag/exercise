#include <stdio.h>
/* invert(x,p,n) returns x with the n bits that begin at position p inverted(i.e., 1 changed into 0 and vice versa), leaving the others unchanged */
unsigned invert(unsigned x, int p, int n) {
	unsigned bit = (~0 << (p-n+1)) & ((unsigned) ~0 >> (31-p));
	return x ^ bit;
}
main() {
	printf("%x\n", invert(0xff, 4,3));
}
