// AUTHOR: WangQiang
// CREATE DATE:   20140707
// LAST UPDATE DATE: 20140707
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
//We suppose content[sizes] is big enough to hold the input. What will happen if the input is too big is undefined, so be cautious not to exceed the limit
int readlines(char content[], int sizes, char *lineptr[], int maxlines)	{
	int len, nlines;
//	int maxlines = sizes / MAXLEN;

	nlines = 0;
	while ((len = getline1(content, MAXLEN)) > 0)
		if (++nlines >= maxlines)
			return -1;
		else {
			*lineptr++ = content;
			content[len - 1] = '\0';	
			content += len;
//			line[len-1] = '\0'; /* delete newline */
//			strcpy(p, line);
//			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)	{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
