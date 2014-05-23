// Author: WangQiang
// Date:   20140523
// EMAIL:  cntqrxj@gmail.com

#include <stdio.h>
#include <ctype.h>
//This version of getint returns EOF for end of file, zero if the next 
//input is not a number, and a positive value if the input contains valid 
//number.
//A fix to getint in the K&R book. When encountering a + or - not followed 
//by a digit as a valid representation of zero, push such a character back
//on the input
int getint(int *pn) {
	int c, sign;
	int tmp;
	int getch(void);
	void ungetch(int);

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}	
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		tmp = c;
		c = getch();
		if (!isdigit(c)) {
			ungetch(c);
			ungetch(tmp);
			printf("%c\n", c);
			printf("%c\n", tmp);
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;	
}

int main() {
	int n;

	printf("%d\n", getint(&n));
	printf("%d\n", n);
	return 0;
}
