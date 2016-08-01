/*************************************************************************
	> File Name: ex1-5.c
	> Author:
	> Mail:
	> Created Time: Mon 01 Aug 2016 07:25:27 PM CST
 ************************************************************************/

#include <stdio.h>
/* print Fahrenheit-Celsius table */
int main()
{
    int fahr;
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    return 0;
}
