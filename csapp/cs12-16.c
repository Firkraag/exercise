/* 
 * hello.c - Pthreads "hello, world" program 
 */
/* $begin hello */
#include "csapp.h"
void *thread(void *vargp);                    //line:conc:hello:prototype

int main(int argc, char *argv[])                                    //line:conc:hello:main
{
	if (argc == 1)
	{
		printf("Usage: %s <nthreads>\n", argv[0]);
		exit(0);
	}

	int n = atoi(argv[1]);
    pthread_t *tidp = (pthread_t *) Malloc(sizeof(pthread_t) * n);                            //line:conc:hello:tid
	int i;

	for (i = 0; i < n; i++)
		Pthread_create(&tidp[i], NULL, thread, NULL); //line:conc:hello:create
	for (i = 0; i < n; i++)
    	Pthread_join(tidp[i], NULL);                  //line:conc:hello:join
    exit(0);                                  //line:conc:hello:exit
}

void *thread(void *vargp) /* thread routine */  //line:conc:hello:beginthread
{
    printf("Hello, world!\n");                 
    return NULL;                               //line:conc:hello:return
}                                              //line:conc:hello:endthread
/* $end hello */
