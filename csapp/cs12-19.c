#include "csapp.h"

int readcnt;
sem_t mutex, w;

void read(void) {
	while (1)
	{
		P(&mutex);
		readcnt;
		if (readcnt == 1)
			P(&w);
		V(&mutex);

		P(&mutex);
		readcnt--;
		if (readcnt == 0)
			V(&w);
		V(&mutex);
	}
}


void writer(void)
{
	while (1)
	{
		P(&r);
		P(&w);

		if (readcnt >= 1)
			V(&r);
		else
			V(&w);
}
