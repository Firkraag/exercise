/*************************************************************************
	> File Name: ex1-17.c
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Aug 2016 10:53:05 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define MAXCHARS 80 
int getline2(char line[], int maxline);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline2(line, MAXLINE)) > 0)
        // print all input lines that are longer than 80 characters
        if (len > MAXCHARS)
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
