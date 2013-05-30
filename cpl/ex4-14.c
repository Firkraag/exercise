#include <stdio.h>
#define swap(t, x, y) { t temp; temp = x; x = y; y = temp; }

main() {
	int x=10, y=5;
	swap(int, x, y)
	printf("%d, %d\n", x, y);
}
	
