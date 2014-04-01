#include <stdio.h>

main() {
	int i;

	for (i = -300; i < 300; i++)
		printf("%d, %d\n", i, fits_bits(i, 9));
//	printf("%x\n", bit(0xff00ff00, 17));
}

