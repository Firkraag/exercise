//Usage: make two soft link to compiled code: lower and upper
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char *argv[]) {
	int c;

	if (strcmp(argv[0], "lower") == 0) 
		while ((c = getchar()) != EOF)
			putchar(tolower(c));
	else if (strcmp(argv[0], "upper") == 0)
		while ((c = getchar()) != EOF)
			putchar(toupper(c));
	printf("%s\n", argv[0]);
	return 0;
}
	
