#include <string.h>
#include <stdio.h>
/* strcpy: copy at most n characters of t to s */
void strncpy1(char *s, char *t, int n)
{
	while (n-- && (*s++ = *t++))
		;
	*s = '\0';
}
void strncat1(char *s, char *t, int n) {
	s = s + strlen(s);

	while (n-- && (*s++ = *t++) )
		;
	*s = '\0';
}
/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp1(char *s, char *t, int n) {
	for (; n-- && (*s == *t); s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
int main() {
	char s[30];
	char t[30] = "abcdefghibdafj";
	strncpy1(s, t, 10);
	printf("%s\n", s);
  strncat1(s, t, 3);
	printf("%s,%d\n", s, strcmp1(s,t,9)); 
	char a[30] = "abcde";
	char b[30] = "fghijklmn";
	strncat1(a, b, 30);
	printf("%s,%d\n", a, strcmp1(a,b,5));
	printf("%d\n", strcmp1("abc", "dbc", 5));
	return 0;
}

