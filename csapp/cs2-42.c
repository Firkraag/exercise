#include <stdio.h>

int div16(int x) {
	int bias = (x >> 31) & 0xf;
	return (x + bias) >> 4;
}

//int main() {
	//printf("%d\n", div16(-200));
//}
