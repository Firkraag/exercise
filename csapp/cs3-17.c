#include <stdio.h>
	
int gotodiff(int x, int y) {
	int result;
	if (x < y) 
		goto y_g_x;
	result = x - y;
	goto done;
y_g_x:
	result = y - x;
done:
	return result;

