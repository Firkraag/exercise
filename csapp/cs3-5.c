#include <stdio.h>

void decode1(int *xp, int *yp, int *zp) {
	int a = *xp;
	int b = *yp;
	int c = *zp;
	*xp = c;
	*yp = a;
	*zp = b;
}

