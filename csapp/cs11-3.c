#include "csapp.h"

int main(int argc, char *argv[]) {
	struct in_addr in;
	
	inet_aton(argv[1], &in);
	printf("0x%x\n", ntohl(in.s_addr));
	return 0;
}
