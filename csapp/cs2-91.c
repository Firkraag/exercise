#include <stdio.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xff;
	unsigned frac = f & 0x7FFFFF;

	if (exp == 0xff && frac != 0)
		return f;
	else {
		sign = sign ^ 1;
		return (sign << 31) | (exp << 23) | frac;
	}
}

main() {
	printf("0x%x\n", float_negate(0xff800001));
}
