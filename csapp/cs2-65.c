#include <stdio.h>

int bit(int x, int k) {
	return 0x1 & (x >> k - 1);
}
//Return 1 when x contains an even number of 1s; 0 otherwise. You may assume that data type int has w = 32 bits
int even_ones(unsigned x) {
	int i;
	int counter = 0;

	for (i = 1; i <= 32; i++)
		if (bit(x, i) == 1)
			counter = counter + 1;
	return counter;
}	

int main() {
	int i;
	
	for (i = 1; i <= 256; i++)
		printf("%d, %d\n", i, even_ones(i));

}
