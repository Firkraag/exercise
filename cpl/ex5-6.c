// AUTHOR: WangQiang
// CREATE DATE:   20140704
// LAST UPDATE DATE: 2014075
// EMAIL:  cntqrxj@gmail.com

#include <stdio.h>

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

int main() {
	char s[100];

	printf("%d\n", getline1(s, 5));
	printf("%s", s);
	return 1;
}
