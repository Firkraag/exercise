#include <stdio.h>
#include <unistd.h>

unsigned int snooze(unsigned int secs) {
	unsigned time_left = sleep(secs);

	printf("Slept for %u of %u secs.\n", secs - time_left, secs);
	return time_left;
}
