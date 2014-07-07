// AUTHOR: WangQiang
// CREATE DATE:   20140704
// LAST UPDATE DATE: 2014075
// EMAIL:  cntqrxj@gmail.com

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUMBER '0'

// pointer version of getline
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

//pointer version of atoi
//atoi: convert characters in s to n
int atoi(char *s) {
	int c, n;
	int sign;

	while (isspace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if ((c = *s) == '+' || c == '-')
		s++;	
	n = 0;
	for (n = 0; isdigit(c = *s); s++) 
//	while (((c = *s++) >= '0') && (c <= '9'))
		n = 10 * n + (c - '0');
	return sign * n;
}

/* reverse: reverse string s in place */
//pointer version
void reverse(char *s) {
	int c;
	char *end = s + strlen(s) - 1;
	
	while (s < end)
	{
		c = *s;
		*s++ = *end;
		*end-- = c;
	}
}

//pointer version of itoa
//itoa: convert n to characters in s 
void itoa(int n, char *s) {
	int sign;
	char *start = s;	

	if ((sign = n) < 0)
		n = -n;
	do {
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(start);
}

/* strindex: return index of t in s, -1 if none */
//pointer version
int strindex(char *s, char *t) {
	char *s1, *s2;
	char *t1;
	
	for (s1 = s; *s1 != '\0'; s1++) {
		for (s2 = s1, t1 = t;*t1 != '\0' && *s2 == *t1;s2++, t1++)
			;
		if (t1 > t && *t1 == '\0')
			return s1 - s;
	}	
	return -1;
}

/* getop: get next character or numeric operand */
//pointer version of getop
int getop(char *s) {
	int c;
	int getch(void);
	void ungetch(int);

	while ((*s = c = getch()) == ' ' || c == '\t')
		;
	*(s + 1) = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a number */
	if (isdigit(c))	/* collect integer part */
		while (isdigit(*++s = c = getch()))
			;
	if (c == '.')	/* collect fraction part */
		while (isdigit(*++s = c = getch()))
			;
	*s = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}


int main(int argc, char *argv[]) {
	char s[100];

//	printf("%d\n", getline1(s, 5));
//	printf("%s", s);
	//printf("%d\n", atoi(argv[1]));
	//itoa(10000, s);
	//printf("%s\n", s);
	printf("%d\n", strindex(argv[1], argv[2]));	
	return 1;
}
