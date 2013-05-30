#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <math.h>
#include "calc.h"
#define MAXOP 100 /* max size of operand or operator */

/* reverse Polish calculator */
main() {
	int type;
	double op2, a;
	char s[MAXOP];
	while (getop(s) != '\0') {
		switch (s[0]) {
		case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			getop(s);
			if (isdigit(s[0]))
				push(-1.0 * atof(s));
			else {
				ungetch(s[0]);
				op2 = pop();
				push(pop() - op2);
			}
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int) pop() % (int) op2);
			else 
				printf("error:zero divisior\n");
			break;
		case '\n':
			printf("\t%.8g\n", a = pop());
			break;
		case 'p':	// print the top element of the stack without popping
			print();	
			break;
		case 'c':
			clear();//clear the stack
			break;
		case 's':
			swap2();// swap the top two elements
			break;
		case 'd':
			duplicate();
			break;
		case 'e':
			push(exp(pop()));
			break;
		case 'i':
			push(sin(pop()));
			break;
		case 'a':
			push(a);	//a is the variable for the most recently printed value.
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
