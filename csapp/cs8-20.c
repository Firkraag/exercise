#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;
int main(int argc, char *argv[]) {
	execve("/bin/ls", argv, environ);
	perror("execve error");
	return 1;
}
