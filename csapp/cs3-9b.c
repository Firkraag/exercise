#include <stdio.h>

int arith(int x, int y, int z) {
	int t1 = x ^ y;
	int t2 = t1 >> 3;
	int t3 = ~t2;
	int t4 = t3 - z;
}
