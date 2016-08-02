/*************************************************************************
	> File Name: ex1-16.c
	> Author:
	> Mail:
	> Created Time: Tue 02 Aug 2016 10:44:20 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline2(line, MAXLINE)) > 0)
        printf("%s", line);
    return 0;
}
/* getline2: read a line into s, return length */
int getline2(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
