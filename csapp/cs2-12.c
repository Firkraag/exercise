#include <stdio.h>

main()
{
	int x = 0x87654321;

	
	printf("Question A:\n0x%x\nQuestion B:\n0x%x,0x%x,0x%x\nQuestion C:\n0x%x\n", x & 0xff, ~(x ^ 0xff),
		   (~x) ^ 0xff, x ^ (~ 0xff), x | 0xff);
//~(x ^ 0xff), (~x) ^ 0xff, x ^ (~ 0xff) have same result

}
