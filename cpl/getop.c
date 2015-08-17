#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER '0'

//int getch(void);
//void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[], char str_cat[], int *position)	{
	int i = *position;
	int j;
	int c;

	while ((s[0] = c = str_cat[i]) == ' ' || c == '\t')
		i++;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	{	
		*position = ++i;
		return c;	/* not a number */
	}
	j = 0;
	if (isdigit(c))	/* collect integer part */
		while (isdigit(s[++j] = c = str_cat[++i]))
			;
	if (c == '.')	/* collect fraction part */
		while (isdigit(s[++j] = c = str_cat[++i]))
			;
	s[j] = '\0';
	if (c != '\0')
		*position = i;
	return NUMBER;
}
