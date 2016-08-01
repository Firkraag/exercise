/*************************************************************************
	> File Name: ex1-10.c
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Aug 2016 09:33:51 PM CST
 ************************************************************************/

#include<stdio.h>

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'
/* copy input to output, replacing each tab by \t, each backspace by \b, and each backslash by \\, making tabs and backspaces visible in an unambiguous way */
int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == TAB) {
            putchar('\\');
            putchar('t');
        }
        else if (c == BACKSLASH) {
            putchar('\\');
        }
        else if (c == BACKSPACE) {
            putchar('\\');
            putchar('b');
        }
        else {
            putchar(c);
        }
    }
    return 0;
}
