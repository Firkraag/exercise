/*************************************************************************
	> File Name: ex1-9.c
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Aug 2016 09:15:31 PM CST
 ************************************************************************/

#include<stdio.h>

#define TAB '\t'
#define BLANK ' '
/* copy input to output, replacing each string of one or more blanks by a
single blank */
int main()
{
    int c;
    int blank = 0;

    while ((c = getchar()) != EOF) {
        if (blank == 1) {
            if (c != BLANK) {
                putchar(BLANK);
                putchar(c);
                blank = 0;
            }
        }
        else if (c == BLANK) {
            blank = 1;
        }
        else {
            putchar(c);
        }
    }
    if (blank == 1) {
        putchar(BLANK);
    }
    return 0;
}
