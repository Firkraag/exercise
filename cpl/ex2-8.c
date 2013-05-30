#include <stdio.h>
unsigned rightrot(unsigned x,int n) {
	return (x >> n) | (x << (32 - n));
}
main() {
	printf("%x\n", rightrot(123,4));
}
