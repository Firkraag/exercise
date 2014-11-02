#include <stdio.h>

void good_echo() {
	char buf[8];

	fgets(buf, 8, stdin);
	fputs(buf, stdout);
}

int main(void) {
	good_echo();
	return 0;
}
