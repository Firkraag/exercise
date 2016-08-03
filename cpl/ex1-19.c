/*************************************************************************
	> File Name: ex1-19.c
	> Author:
	> Mail:
	> Created Time: Tue 02 Aug 2016 10:59:32 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAXLINE 1000 /* maximum input line length */
int getline2(char line[], int maxline);
void reverse(char s[], int len);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline2(line, MAXLINE)) > 0) {
        reverse(line, line[len - 1] == '\n' ? len - 1 : len);
        printf("%s", line);
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

/* reverse: reverse character string s */
void reverse(char s[], int len)
{
    int i = 0;
    int j = len - 1;;
    int tmp;

    while (i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}
