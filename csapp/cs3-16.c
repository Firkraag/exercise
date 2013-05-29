#include <stdio.h>

void cond(int a, int *p) {
	if(p == 0)
		goto done;
	if(a <= 0)
		goto done;
	*p += a;
	done: 
		return;
}

