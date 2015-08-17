#include <stdio.h> 
#include <stdlib.h>	/* for atof() */
#include <string.h>
 
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char *, char *, int *);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(int argc, char *argv[])	{
	int type;
	double op2;
	char s[MAXOP];
	int i;
	char *str_cat;
	int *arg_len = (int *) calloc(argc, sizeof(int));
	int position;
	int total;

	for (total = 0, i = 1; i < argc; i++) 
		total += ((arg_len[i] = strlen(argv[i])) + 1);
	total++;
	str_cat = (char *) calloc(total, sizeof(char));				
	str_cat[0] = '\0';
	for (position = 0, i = 1; i < argc; i++) {
		strcat(str_cat, argv[i]);
		position += (arg_len[i] + 1);
		str_cat[position - 1] = ' ';
		str_cat[position] = '\0';
	}					
	str_cat[position - 1] = '\n';
//	printf("%s\n", str_cat);
	position = 0;
	while ((type = getop(s, str_cat, &position)) != '\0')
	{
//		printf("%d, %c, type = %c\n", position, str_cat[position], type);
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
		
	//printf("%s", str_cat);

	free(str_cat);
	free(arg_len);
	return 0;
}
