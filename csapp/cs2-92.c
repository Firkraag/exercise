#include <stdio.h>

typedef unsigned float_bits;

/* Compute |f|. If f is NaN, then return f. */
float_bits float_absval(float_bits f) {
	unsigned sign = 0;
	unsigned exp = (f >> 23) & 0xff;
	unsigned frac = f & 0x7FFFFF;

	if (exp == 0xff && frac != 0)
		return f;
	else 
		return (sign << 31) | (exp << 23) | frac;
	
}

main() {
	printf("0x%x\n", float_absval(0x82000010));
}
