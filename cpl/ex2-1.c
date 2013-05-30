#include <stdio.h>

main() {
	char char_bit = sizeof(char) << 3;
	short short_bit = sizeof(short) << 3;
	int int_bit = sizeof(int) << 3;
	long long_bit = sizeof(long) << 3;
	printf("Maximum value of type signed char is %d\n", (1<<(char_bit-1))-1);
	printf("Minimum value of type signed char is %d\n", (char) (1<<(char_bit-1)));
	printf("Maximum value of type unsigned char is %u\n", (unsigned char)-1);
	printf("Maximum value of type signed short is %d\n", (1<<(short_bit-1))-1);
	printf("Minimum value of type signed short is %d\n", (short) (1<<(short_bit-1)));
	printf("Maximum value of type unsigned short is %u\n", (unsigned short) -1);
	printf("Maximum value of type signed int is %d\n", (1<<(int_bit-1))-1);
	printf("Minimum value of type signed int is %d\n", 1<<(int_bit-1));
	printf("Maximum value of type unsigned int is %u\n", (unsigned) -1);
	printf("Maximum value of type signed long is %ld\n", (1l<<(long_bit-1))-1);
	printf("Minimum value of type signed long is %ld\n", 1l<<(long_bit-1));
	printf("Maximum value of type unsigned long is %lu\n", (unsigned long) -1l);
}


