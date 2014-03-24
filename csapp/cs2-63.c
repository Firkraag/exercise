#include <stdio.h>

// judge the kth bit of x, if it is 1, return 1, otherwise return 0
int bit(int x, int k) {
	return 0x1 & (x >> k - 1);
	
} 
int sra(int x, int k) {
	int xsrl = (unsigned) x >> k;
	int int_size = sizeof(int) << 3;
	int b = bit(x, int_size);
	
	if(b == 0)
		return xsrl;
	else
		return xsrl | (~0x0 << int_size - k);

}
unsigned srl(unsigned x, int k) {
	unsigned xsra = (int) x >> k;
	int int_size = sizeof(int) << 3;
	return xsra & ((unsigned) ~0x0 >> k); 
}

main() {
	printf("%x, %x\n",(unsigned) 0x87654321 >> 31, sra(0x87654321, 31));
	printf("%x, %x\n",(int) 0x77654321 >> 30, srl(0x77654321, 30));	
}
