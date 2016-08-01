/*************************************************************************
	> File Name: ex1-4.c
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Aug 2016 07:15:56 PM CST
 ************************************************************************/

#include<stdio.h>
/* print Celsius-Fahrenheit table
for celsius = 0, 20, ..., 300; floating-point version */
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    celsius = lower;
    printf("Celsius-Fahrenheit Table\n\n");
    while (celsius <= upper)
    {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}

