#include <stdio.h>
#include <limits.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
/* convert the integer n into a base b character representation in the string s, handles INT_MIN correctly*/

void itob(long n, char s[], int b) {	
	int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % b + '0';
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
main() {
	int n = INT_MIN; 
	char s[40];
	itob(n, s, 2);
	printf("%s\n", s);
}
