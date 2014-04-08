#include <stdio.h>
#define M 31
#define N 8

int arith(int x, int y) {
	return x * M + y / N;
}

int optarith(int x, int y) {
	int t = x;

	x <<= 5;
	x -= t;
	if (y < 0)
		y += 7;
	y >>= 3;
	return x + y;
}

//int main() {
	//int i;
//	
	//for (i = 1; i <= 100; i++)
		//printf("%d, %d\n", arith(i, 8), optarith(i, 8));
//}	
