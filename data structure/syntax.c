#include <stdio.h>
struct stack_record { 
    unsigned int stack_size; 
    int top_of_stack; 
    int *stack_array; 
}; 
typedef struct stack_record *STACK;
void syntax_check(void) {
	int c,d;
	STACK stack = create_stack(50);
	while ((c = getchar()) != EOF) {
		switch (c) {
		case '(': case '{': case '[':
			push(c, stack);
			break;
		case ')': case '}': case ']':
			if (is_empty(stack)) {
				printf("error110");
				return;
			}
			else if ((d = true_pop(stack)) != '(' && c == ')') {
				printf("error");
				return;
			}
			else if (d != '{' && c == '}') {
				printf("error");
				return;
			}
			else if (d != '[' && c == ']') {
				printf("error");
				return;
			}
		}
	}
	if (is_empty(stack)) {
		printf("no syntax error");
		return;
	}
	else {
		printf("error\n");
		return;
	}
}		
main() {
	syntax_check();

				
		
