#include <stdio.h>

typedef unsigned float_bits;

/* Compute 0.5 * f. If f is NaN, then return f. */
float_bits float_half(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xff;
	unsigned frac = f & 0x7fffff;
	unsigned least_significant_two_bits = 0x3 & frac;

	if (exp == 0x0) {
		if (least_significant_two_bits != 0x3)
			frac = frac >> 1;
		else
			frac = (frac >> 1) + 0x1;
	}
			
	else if (exp == 0x1) {
		exp = 0x0;
		
		if (least_significant_two_bits != 0x3)
			frac = frac >> 1;
		else {
			printf("love\n");
			frac = (frac >> 1) + 0x1;
		}
			frac = (0x1 << 22) | frac;
	}
	else if (exp < 0xff)
		exp--;
	else
		return f;
	return (sign << 31) | (exp << 23) | frac;
}

int main() {
	printf("0x%x\n", float_half(0xff800000));
}
