#include <stdio.h>
/* strcat: concatenate t to the end of s; s must be big enough */
void strcat1(char *s, char *t) {
	while (*s)	/* find end of s */
		s++;
	while (*s++ = *t++)	/* copy t */
		;
}

int main() {
	char s[30] = "abcdef";
	char t[10] = "def";
	char *p = s;

	printf("%c\n", *p++);
	printf("%c\n", *p);
	strcat1(s, t);
	printf("%s\n", s);
	return 0;
}
