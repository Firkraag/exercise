#include <stdio.h>
#include <limits.h>

//Determine whether arguments can be added without overflow
//This function should return 1 if arguments x and y can be added without
//causing overflow 
int tadd_ok(int x, int y) {
	int sum = x + y;
	int neg_over = x < 0 && y < 0 && sum >= 0;
	int pos_over = x > 0 && y > 0 && sum < 0;
	
	return !neg_over && !pos_over; 
	//if ((x < 0 && y < 0 && sum >= 0) || (x > 0 && y > 0 && sum < 0))
		//return 0;
	//else
		//return 1;
}

//int main() {
	//int x = 100;
	//int y = 100;
//
	//printf("%d\n", tadd_ok(x, y));
//}
