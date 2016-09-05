/* 
 * hellobug.c - "hello, world" program with a bug
 */
/* $begin hellobug */
#include "csapp.h"
void *thread(void *vargp);

int main() 
{
    pthread_t tid;

    Pthread_create(&tid, NULL, thread, NULL);
	Pthread_join(tid, NULL);
//	Pthread_cancel(tid);
//	return 0;
//	exit(0);
//    Pthread_exit(0);
}

/* thread routine */
void *thread(void *vargp) 
{
    Sleep(1);
    printf("Hello, world!\n"); 
	//Pthread_exit(0);
    return NULL;
}
/* $end hellobug */
