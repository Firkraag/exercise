#include <stdio.h>
/* lower converts upper case letters to lower case, with a conditional expression instead of if-else */
int lower(int c) {
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
main() {
	int c;
	for (c = 'A';c <= 'Z'; c++)
		printf("%c ", lower(c));
	printf("\n");
	}
