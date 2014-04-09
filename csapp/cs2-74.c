#include <stdio.h> 
#include <limits.h>

//Determine whether arguments can be substracted without overflow
//This function should return 1 if the computation x - y does not overflow.
int tsub_ok(int x, int y) {
	int sum = x - y;

	return !((x >= 0 && y == INT_MIN) || (x < 0 && y > 0 && sum >= 0) || (x > 0 && y < 0 && y > INT_MIN && sum < 0));
}

//main() {
	//int i;
//	
	//printf("INT_MIN = %d\n", INT_MIN);	
	////for (i = -100; i < 100; i++)
		//////printf("i = %d, i - INT_MIN = %d, i + INT_MIN = %d\n", i, i - INT_MIN, i + INT_MIN);
		////printf("i = %d, result = %d\n", i, tsub_ok(i, INT_MIN));
	//printf("%d\n", tsub_ok(INT_MIN, 1));
	//printf("%d\n", INT_MIN - 1);
	////printf("%d\n", tsub_ok(INT_MAX, 1));
//}
