#include <stdio.h>
#include "cpl.h"
int strlen1(char *s) {
	int n;
	
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}
int strlen2(char *s) {
	char *p = s;
	
	while (*p != '\0')
		p++;
	return p - s;
}
main() {
	char *a = "abce";
	printf("%d\n", strlen1("hello, world"));
	printf("%d\n", 0xfffffff0);
	printf("%c\n", getchar());
	printf("%s\n", a);
	buf[4] = 4;
	buf[5] = 5;
	bufp = 5;
	printf("%d, %d\n", getch(), bufp);
	printf("%d, %d, %d\n", bufp++, bufp--, bufp);
	int i = 1;
	printf("%d, %d\n", i++, i);
	
}

