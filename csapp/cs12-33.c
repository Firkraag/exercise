#include "csapp.h"

sigjmp_buf buf;


void *thread(void *vargp);

char *tfgets(char *s, int size, FILE *stream)
{
	pthread_t tid;

	Pthread_create(&tid, NULL, thread, NULL);
	printf("main thread id: %d\n", pthread_self());
	printf("peer thread id: %d\n", tid);
	if (!setjmp(buf))
	{
//		printf("Confuse\n");
		pause();
		char *as = fgets(s, size, stream);
		printf("main thread id: %d\n", pthread_self());
//		printf("setjmp Confuse\n");
		Pthread_cancel(tid);
		return as;
	}
	else
	{
		printf("main thread id: %d\n", pthread_self());
		sleep(5);
//		printf("longjmp Confuse\n");
		return NULL;
	}

}

void *thread(void *vargp)
{
	printf("peer thread id: %d\n", pthread_self());
	if (sleep(5) == 0)
		longjmp(buf, 1);
	printf("peer thread id: %d\n", pthread_self());
	printf("Reach here?\n");	
	return NULL;
}

