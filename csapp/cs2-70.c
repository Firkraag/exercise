#include <stdio.h>

int fits_bits(int x, int n) {
	int N_MIN = -(1 << (n - 1));
	int N_MAX = (1 << (n - 1)) - 1;
	printf("%d\n", N_MIN);
	printf("%d\n", N_MAX);
}
	
int main() {
	fits_bits(10, 32);

}
