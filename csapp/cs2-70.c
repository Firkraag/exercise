#include <stdio.h>

//Return 1 when x can be represented as an n-bit, 2's complement
//number; 0 otherwise
//Assume 1 <= n <= w
int fits_bits(int x, int n) {
	int size = sizeof(int) << 3;
	int head = x >> (n - 1);
	
	return (head == ~0) | (head == 0);
}
