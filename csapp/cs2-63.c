#include <stdio.h>

//Judge the kth bit of x, if it is 1, return 1, otherwise return 0
//int bit(int x, int k) {
	//return 0x1 & (x >> k - 1);
//	
//} 
//Another version
int bit(int x, int k) {
	return !!((0x1 << k - 1) & x);
}

//Function sra performs an arithmetic right shift using a logical right shift given by value xsrl
int sra(int x, int k) {
	int xsrl = (unsigned) x >> k;
	int int_size = sizeof(int) << 3;
	int b = bit(x, int_size);
	
	if(b == 0)
		return xsrl;
	else
		return xsrl | (~0x0 << int_size - k);

}

//Function srl performs a logical right shift using an arithmetic right shift given by value xsra
unsigned srl(unsigned x, int k) {
	unsigned xsra = (int) x >> k;
	int int_size = sizeof(int) << 3;

	return xsra & (~((~0x0) << int_size - k)); 
}

//main() {
	//printf("%x, %x\n",(unsigned) 0x87654321 >> 31, sra(0x87654321, 31));
	//printf("%x, %x\n",(int) 0x77654321 >> 30, srl(0xe7654321, 31));	
//}
