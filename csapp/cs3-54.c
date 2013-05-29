#include <stdio.h>

int decode2(int x, int y, int z) {
	int a;
	int b;
	
	a = z;
	a = a - y;
	b = a;
	b = b << 15;
	b = b >> 15;
	a = x ^ a;
	b = a * b;
	return b;
}

