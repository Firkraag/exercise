#include <stdio.h>

//Return 1 when any even bit of x equals 1; 0 otherwise. You may assume that data type int has w = 32 bits.
int any_even_one(unsigned x) {
	return !!(x & 0xaaaaaaaa);

}

//main() {
	//unsigned int i;
	//for (i = 1; i < 32; i++)
		//printf("%x\n", any_even_one(i));
//}
