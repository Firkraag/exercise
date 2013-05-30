#include <stdio.h>

struct stack_record {
    unsigned int stack_size;
    int top_of_stack;
    int *stack_array;
};
typedef struct stack_record *STACK;
void in2post(void) {
	int c;
	STACK stack = create_stack(50);
	while ((c = getchar()) != EOF) {
		if (isalnum(c))
			putchar(c);
		else if (c == 
	}
	while (true_pop(stack) != ;
}

		
main() {
	in2post();
}
