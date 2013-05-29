#include <stdio.h>

int any_even_one(unsigned x) {
	return (x & 0xaaaaaaaa)  != 0;

}

main() {
	printf("%x\n", any_even_one(0x21));
}
