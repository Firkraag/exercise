/* 
 * Readers-writers solution which favors writes instead of readers
*/
/* $begin rw2 */
#include "csapp.h"

/* Global variables */
int readcount;      /* Initially = 0 */
sem_t mutex, r, w; /* All initially = 1 */

void reader(void) 
{
    while (1) {
	P(&r);
	V(&r);
	P(&mutex);
	readcount++;
	if (readcount == 1)
	    P(&w);
	V(&mutex);

	/* Critical section: */
	/* Reading happens   */

	P(&mutex);
	readcount--;
	if (readcount == 0)
	    V(&w);
	V(&mutex);
    }
}

void writer(void) 
{
    while (1) {
	P(&r);
	P(&w);

	/* Critical section: */
	/* Writing happens   */

	V(&w);
	V(&r);
    }
}
/* $end rw2 */

