#include <stdio.h>
#include <string.h>
#include <limits.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}	
}
/* another version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough */
void itoa(long n, char s[], int width) {
	int i, sign;
	int blank;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
	blank = width - strlen(s);
	if (blank > 0) {
		for (i = width; i >= blank; i--)
			s[i] = s[i - blank];
		for (i = 0; i < blank; i++)
			s[i] = ' '; 
	}
}
main() {
	int n = 196;
	char s[30];
	itoa(n,s,6);
	printf("%s\n", s);
}
