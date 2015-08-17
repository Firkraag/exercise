#include "csapp.h"

int main(int argc, char *argv[]) {
	struct in_addr in;

	in.s_addr = htonl(strtol(argv[1], NULL, 16));
	printf("%s\n", inet_ntoa(in));
	return 0;
}
