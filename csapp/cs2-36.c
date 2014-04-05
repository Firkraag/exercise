#include <stdio.h>
#include <limits.h>

/* Determine whether arguments can be multiplied without overflow */
/* When overflow, return 0; otherwise return 1 */
/* It is a version of tmul_ok that uses 64-bit precision of data type long  long for the case where data type int has 32 bits */
int tmul32_ok(int x, int y) {
//	int p = x * y;
	long long llp = (long long) x * y;

//	return p == llp;
	return (int) llp == llp;
}

//int main() {
	//printf("%d\n", tmul32_ok(INT_MIN, INT_MAX));
//}
