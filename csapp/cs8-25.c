#include "csapp.h"

jmp_buf buf;

void handler(int sig)
{
	siglongjmp(buf, 1);
}

char *tfgets(char *s, int size, FILE *stream)
{
	Signal(SIGALRM, handler);
	Alarm(5);

	if (!sigsetjmp(buf, 1))
		return fgets(s, size, stream);
	else
	{
		return NULL;
	}
}

int main() {
	char s[100];
	char *ptr = tfgets(s, 50, stdin);
	printf("%p\n", ptr);
	return 0;
}
