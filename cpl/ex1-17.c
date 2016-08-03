/*************************************************************************
	> File Name: ex1-17.c
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Aug 2016 10:53:05 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAXLINE 20 /* maximum input line length */
#define MAXCHARS 10 
#define TRUE 1
#define FALSE 0
int getline2(char line[], int maxline);

/* print all input lines that are longer than MAXCHARS characters */
int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    int partial = FALSE; /* A flag indicating whether we are printing part of a line */ 

    while ((len = getline2(line, MAXLINE)) != 0) {
        if (partial) {
            printf("%s", line);
            /* we are done printing the line */
            if (line[len - 1] == '\n') {
                partial = FALSE;
            }
        }
        else if (len <= MAXCHARS) {
            ;
        }
        else {
            printf("%s", line);
            if (line[len - 1] != '\n') {
                partial = TRUE;
            }
        }
    }
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
