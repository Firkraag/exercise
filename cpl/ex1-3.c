/*************************************************************************
	> File Name: ex1-3.c
	> Author:
	> Mail:
	> Created Time: Mon 01 Aug 2016 07:09:46 PM CST
 ************************************************************************/

#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    printf("Fahrenheit-Celsius Table\n\n");
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
