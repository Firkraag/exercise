#include "csapp.h"

int mysystem(char *command) {
	pid_t pid;
	char *arg[] = {"/bin/sh", "-c", command, NULL};
	int status;

	if ((pid = fork()) < 0)
		return -1;
	else if (pid == 0) {
		execve("/bin/sh", arg, environ);
		/* If control reaches here, it means /bin/sh could not be executed. If the value of command is NULL, the exit status will be 0; otherwise 127 */
		if (arg[2] == NULL)
			exit(0);
		else
			exit(127);
	}


	if (waitpid(pid, &status, 0) > 0) {
		if (WIFEXITED(status))
			return WEXITSTATUS(status);
		else
			return -1;
	}
	else
		return -1;
}	

int main(int argc, char *argv[], char *envp[]) {
	printf("%d\n", mysystem(argv[1]));
	return 0;
}
