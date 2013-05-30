#include "stack_array.h"

main() {
	char c, tmp;
	STACK S = create_stack(100);
	int line = 1, chr = 0;
	while ((c = getchar()) != EOF) {
		chr++;
		if (c == '\n') {
			line++;
			chr = 0;
		}
		if (c == '(' || c == '{' || c == '[')
			push(c, S);
		else if (c == ')' || c == '}' || c == ']') {
			if (is_empty(S)) {
				printf("character %c at position %d, %dhas no corresponding opening symbol\n", c, line, chr);
				return -1;
			}
			else {
				tmp = pop(S);
				if ((c == ')' && tmp != '(') || (c == '}' && tmp != '{') || (c ==']' && tmp != '['))
				{
					printf("character %c at position %d, %d and the preceding %c do not match\n", c, line, chr, tmp);
					return -1;
				}
			}
		}
	}
	if (is_empty(S))
		printf("Syntax Correct\n");
	else
		printf("Syntax Not Correct\n");
}
