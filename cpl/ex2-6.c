#include <stdio.h>
unsigned setbits(unsigned x,int p,int n,unsigned y) {
	unsigned bit = (~0 << (p-n+1)) & ((unsigned) ~0 >> (31-p));
	x  = x & ~bit;
	y = (y << (p-n+1)) & bit;
	return x | y;

}
main() {
	printf("%x\n", setbits(0xff,7,3,0x5));
}	
	
