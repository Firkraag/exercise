#include <stdio.h>
#include <limits.h>
/* itoa convert n to characters in s; compared to the original version of itoa, we have changed the type of n from int to long to to handle the largest negative number; the original version can't handle it since when n = INT_MIN, -n = INT_MAX + 1 and overflow occurs */ 
void itoa(long n, char s[]) {
	int i, sign;
/*	if (n == INT_MIN) {
		itoa(n+1,s);
		s[strlen(s) - 1]++;
		return;
	} */
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
}
main() {
	int n = INT_MIN;
	char s[20];	
	itoa(n,s);
	printf("%s\n", s);
}
