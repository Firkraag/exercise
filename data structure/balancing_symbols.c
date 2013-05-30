/* This program checks whether everything is balanced. 
Thus, every right brace, barcket, and parenthesis 
must correspond to their left counterparts. 
Thesequence [()] is legal, but [(]) is wrong. 
For simplicity, only the balancing of parentheses, 
barckets, and braces are checked */

/* The simple algorithm uses a stack and is as follows:
Make an empty stack. Read characters until end of file. 
If the character is an open anything, push it onto the stack. 
If it is a close anything, then if the stack is empty report an error. 
Otherwise, pop the stack. If the symbol popped is not 
the corresponding opening symbol, then report an error. 
At the end of file, if the stack is not empty report an error. */

#include "stack_array.h"

main() {
	char c, tmp;
	int line = 1, char_pos= 0;  /* record position of the symbol */ 

	STACK S = create_stack(100);
	while ((c = getchar()) != EOF) {
		char_pos++;
		if (c == '\n') {
			line++;
			char_pos = 0;
		}
		if (c == '(' || c == '{' || c == '[')
			push(c, S);
		else if (c == ')' || c == '}' || c == ']') {
			if (is_empty(S)) {
				printf("closed symbol %c at position %d, %dhas no corresponding opening symbol\n", c, line, char_pos);
				return -1;
			}
			else {
				tmp = pop(S);
				if ((c == ')' && tmp != '(') || (c == '}' && tmp != '{') || (c ==']' && tmp != '['))
				{
					printf("closed symbol %c at position %d, %d and the previous opening symbol %c do not match\n", c, line, char_pos, tmp);
					return -1;
				}
			}
		}
	}
	if (is_empty(S))
		printf("End of File. Syntax Correct\n");
	else
		printf("End of file. Syntax Not Correct\n");
}
