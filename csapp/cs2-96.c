#include <stdio.h>
#include <limits.h>

typedef unsigned float_bits;

/* 
 * Compute (int) f.
 * If conversion cause overflow or f is NaN, return 0x8000000
*/
int float_f2i(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xff;
	unsigned frac = f & 0x7FFFFF;
	unsigned e;
	int result;
	
	printf("0x%x\n", exp);
	if (exp < 0x7f)
		result = 0;
	else if (exp < 150) {
			e = exp - 127;
			result = (0x800000 | frac) >> (23 - e);
	}
	else if (exp < 158) {
			e = exp - 127;
			result = (0x800000 | frac) << (e - 23);
	} 
	else 
		result = 0x80000000;
	return sign == 0 ? result : -result;
}
int main() {
	int i;
	
	printf("%d\n", float_f2i(0xc1280000));
}
