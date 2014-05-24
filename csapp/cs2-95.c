#include <stdio.h>
#include <limits.h>

typedef unsigned float_bits;

/* Determine the position of leftmost one */	
int leftmost_one_pos(unsigned x) {
	int high = 31;
	int low = 0;
	int middle;
	int result;
	int length = high - low;

	while (length >= 0) {
		middle = (low + high) / 2;
		result = x >> middle;
		if (result == 0x1)
			return middle + 1;
		else if (result > 0x1)
			low = middle + 1;
		else
			high = middle - 1;
		length = high - low;
	}
	return -1;
}

/* Compute (float) i */
float_bits float_i2f(int i) {
	//unsigned sign = f >> 31;
	//unsigned exp = f >> 23 & 0xff;
	//unsigned frac = f & 0x7fffff;
	unsigned sign;
	unsigned exp;
	unsigned frac;
	unsigned round_two_bits;
	int pos;
	
	if (i < 0) {
		sign = 1;
		i = -i;
	}
	else 
		sign = 0;
	pos = leftmost_one_pos(i);
	
	if (pos <= 24 && pos > 0) {
		frac = (i << (24 - pos)) & 0x7fffff; 
		exp = pos + 126;
	}
	else if (pos > 24 && pos < 32) {
		frac = (i >> (pos - 24)) & 0x7fffff;
		round_two_bits = (i >> (pos - 25)) & 0x3;
		if (round_two_bits == 0x3) {
			if (frac == 0x7fffff) {
				frac = 0;
				exp = pos + 127;
			}
			else {
				frac = frac + 1;
				exp = pos + 126;
			}
		}
	}
	else if (pos == 32) 
		return 0xcf000000;
	else 
		return 0x0;
	return (sign << 31) | (exp << 23) | frac;
}

int main() {
	int i;

	for (i = 0; i < 32; i++) 
		printf("%d\t", leftmost_one_pos(1 << i));
	printf("\n");
	printf("0x%x\n", float_i2f(0x03fffffe));
	printf("0x%x\n", float_i2f(0x0));
	return 0;
}
