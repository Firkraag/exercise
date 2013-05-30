#include <stdio.h>
int buf;

int getch(void) {/* get a (possibly pushed-back) character */
	int c;
	if (buf == '\0')
		return getchar();
	else {
		c = buf;
		buf = '\0';
		return c;
	}
}

void ungetch(int c) {		/* push character back on input */
	if (buf != '\0')
		printf("can only store one character\n");
	else
		buf = c;
}
