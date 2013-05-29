#include <stdio.h>
typedef unsigned long long num_t;
void store_prod(num_t *dest, unsigned x, num_t y) {
	*dest = x*y;
}
