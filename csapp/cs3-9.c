#include <stdio.h>

int arith(int x, int y, int z) {
	int t1 = y;
	int t2 = x ^ t1;
	int t3 = t2 >> 3;
	int t4 = (~t3) - z;
	return t4;
}

