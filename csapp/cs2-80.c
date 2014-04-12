#include <stdio.h>

int main() {
	int i;

	for (i = 0; i < 32; i++)
//~((1 << n) - 1)
		printf("0x%x\n", ~((1 << i) - 1));
//(~((1 << m) - 1)) & ((1 << ( m + n)) - 1)
		printf("0x%x\n", (~((1 << 7) - 1)) & ((1 << ( 7 + 8)) - 1));
		
}
