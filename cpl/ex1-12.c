/*************************************************************************
	> File Name: ex1-12.c
	> Author:
	> Mail:
	> Created Time: Tue 02 Aug 2016 12:56:56 PM CST
 ************************************************************************/

#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
int main()
{
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        }
        else {
            putchar(c);
            state = IN;
        }
    }
    return 0;
}
