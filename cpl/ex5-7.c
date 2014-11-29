// AUTHOR: WangQiang
// CREATE DATE:   20140707
// LAST UPDATE DATE: 20140709
// EMAIL:  cntqrxj@gmail.com

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000 /* max length of any input line */

int getline1(char *s, int lim) {
	int c;
	char *origin = s;
	char *end = s + lim;

	while ((s < end) && ((c = getchar()) != EOF) && (c != '\n'))
		*s++ = c;
	if (c == '\n') 
		*s++ = c;
	*s = '\0';
	return s - origin;
} 

/* readlines: read input lines */
/* This procedure store lines in an array supplied by main */
/* Return -1 when too many lines are presented */
/* Return -2 when the array supplied by the main routine is not big enough   to hold the input */
/* Otherwise, return number of lines of input */
//We suppose content[sizes] is big enough to hold the input. What will happen if the input is too big is undefined, so be cautious not to exceed the limit
int readlines(char content[], int sizes, char *lineptr[], int maxlines)	{
	int nlines;
	int len = 0;

	nlines = 0;
	while ((sizes -= len) >= (MAXLEN + 1) && (len = getline1(content, MAXLEN)) > 0)
		if (++nlines >= maxlines)
			return -1;
		else {
			*lineptr++ = content;
			content[len - 1] = '\0';	/* delete newline */	
			content += len;
		}
	if (sizes <= MAXLEN)	//It means the array supplied by 
		return -2;	//the main routine is not big enough
	else
		return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)	{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
