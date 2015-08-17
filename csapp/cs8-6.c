//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
#include "csapp.h"
//extern char **environ; 
int main(int argc, char *argv[], char *envp[]) {
	int i;
//	char **envp = environ;

	printf("Command line arguments:\n");
	for (i = 0; i < argc; i++) 
		printf("\targv[ %d]: %s\n", i, argv[i]);
	printf("Environment variables:\n");
	i = 0;
	for (; *envp != NULL; envp++) 
		printf("\tenvp[ %d]: %s\n", i++, *envp);
	return 0;
}
	
