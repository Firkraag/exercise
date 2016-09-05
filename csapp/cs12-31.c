#include "csapp.h"

sigjmp_buf buf;

void handler(int sig)
{
	siglongjmp(buf, 1);
}

char *tfgets(char *s, int size, FILE *stream)
{
	pid_t pid;
	Signal(SIGUSR1, handler);
	if ((pid = Fork()) == 0)
	{
		sleep(5);
		Kill(getppid(), SIGUSR1); 
//		fgets(s, size, stream);
//		printf("Child: %s\n", s);
		exit(0);
	}
	if (!sigsetjmp(buf, 1))
	{
//		printf("I'm here\n");
		char *as = fgets(s, size, stream);
		sigset_t mask;
		Sigemptyset(&mask);
		Sigaddset(&mask, SIGUSR1);
		Sigprocmask(SIG_BLOCK, &mask, NULL);
		waitpid(pid, NULL, 0);
		Sigprocmask(SIG_UNBLOCK, &mask, NULL);
		return as;
	}
	else
	{
//		printf("I'm here\n");
		waitpid(pid, NULL, 0);
		return NULL;
	}
//	sleep() makes the calling thread sleep until seconds have elapsed or a signal arrives which is not ignored. Since SIGCHLD will be ignored by default, we need install a signal handler
//	if (sleep(10) == 0)
//	{
//		Kill(pid, SIGKILL);
//		waitpid(pid, NULL, 0);
//		return NULL;
//	}
//	else
//	{
//		waitpid(pid, NULL, 0);
//		return s;
//	}
}
