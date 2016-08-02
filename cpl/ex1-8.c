/*************************************************************************
	> File Name: ex1-8.c
	> Author:
	> Mail:
	> Created Time: Mon 01 Aug 2016 09:11:36 PM CST
 ************************************************************************/

#include <stdio.h>
#define NEWLINE '\n'
#define TAB '\t'
#define BLANK ' '
/* count blanks, tabs, and newlines in input */
int main()
{
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == NEWLINE || c == TAB || c == BLANK)
            ++nl;
    printf("%d\n", nl);
    return 0;
}
