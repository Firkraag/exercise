#include "csapp.h"

void handler(int sig) {
	;
}
unsigned int snooze(unsigned int secs) {
	unsigned time_left = sleep(secs);

	printf("Slept for %u of %u secs.\n", secs - time_left, secs);
	return time_left;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <secs>\n", argv[0]);
		return 1;
	}
	Signal(SIGINT, handler);
	snooze(atoi(argv[1]));
	return 0;
}		
