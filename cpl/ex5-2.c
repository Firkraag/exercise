// Author: WangQiang
// Date:   20140523
// EMAIL:  cntqrxj@gmail.com

#include <stdio.h>
#include <ctype.h>
//This version of getfloat returns EOF for end of file, zero if the next 
//input is not a number, and a positive value if the input contains valid 
//number.
//When encountering a + or - not followed 
//by a digit, it is not treated as a valid representation of zero, 
//instead push such a character back on the input and return 0,
//meaning that the next input + or - is a not number
int getfloat(double *pn) {
	int c, sign;
	int tmp;
	double power;
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
		if (!isdigit(c = getch())) {
			ungetch(c);
			ungetch(tmp);
	//		printf("%c\n", c);
	//		printf("%c\n", tmp);
			return 0;
		}
	}
	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.') {
		tmp = c;
		if (!isdigit(c = getch())) {
			ungetch(c);
			ungetch(tmp);
	//		printf("%c\n", c);
	//		printf("%c\n", tmp);
			return 0;
		}
	}
	for (power = 1.0; isdigit(c); c = getch()) {
		power /= 10.0;
		*pn += (c - '0') * power;
	}	
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;	
}

int main() {
	double n;

	printf("%d\n", getfloat(&n));
	printf("%f\n", n);
	return 0;
}
