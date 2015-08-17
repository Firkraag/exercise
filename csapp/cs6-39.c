#include <stdio.h>
#include <math.h>
#define N 16

typedef struct {
		int valid;
		int check;
	} LINE;
int main() {
	LINE line[64];
	unsigned int i, j;
	unsigned int start_addr = 0x0;
	unsigned int addr;
	unsigned set;
	unsigned check;
	int miss = 0, hit = 0;
	for (i = 0; i < 64; i++)
		(line[i]).valid = 0;
	for (i = 0; i < N; i++) 
		for (j = 0; j < N; j++) {
			printf("i: %d, j: %d  ", i, j);
			addr = start_addr + i * 16 * N + j * 16;
			set = (addr & 0x7e0) >> 5;
			check = (addr & 0xfffff800) >> 11;
//			printf("abc\n");
			if (line[set].valid == 0) {
				line[set].valid = 1;
				line[set].check = check;
				miss++;
				printf("miss\n"); 
			}
			else if (line[set].check == check) {
				hit++;
				printf("hits\n"); 
			}
			else {
				line[set].check = check;
				miss++;
				printf("miss\n"); 
			}
			addr = addr + 4;
			set = (addr & 0x7e0) >> 5;
			check = (addr & 0xfffff800) >> 11;
//			printf("abc\n");
			if (line[set].valid == 0) {
				line[set].valid = 1;
				line[set].check = check;
				miss++;
				printf("miss\n"); 
			}
			else if (line[set].check == check) {
				hit++;
				printf("hits\n"); 
			}
			else {
				line[set].check = check;
				miss++;
				printf("miss\n"); 
			}
			addr = addr + 4;
			set = (addr & 0x7e0) >> 5;
			check = (addr & 0xfffff800) >> 11;
//			printf("abc\n");
			if (line[set].valid == 0) {
				line[set].valid = 1;
				line[set].check = check;
				miss++;
				printf("miss\n"); 
			}
			else if (line[set].check == check) {
				hit++;
				printf("hits\n"); 
			}
			else {
				line[set].check = check;
				miss++;
				printf("miss\n"); 
			}
			addr = addr + 4;
			set = (addr & 0x7e0) >> 5;
			check = (addr & 0xfffff800) >> 11;
//			printf("abc\n");
			if (line[set].valid == 0) {
				line[set].valid = 1;
				line[set].check = check;
				miss++;
				printf("miss\n"); 
			}
			else if (line[set].check == check) {
				hit++;
				printf("hits\n"); 
			}
			else {
				line[set].check = check;
				miss++;
				printf("miss\n"); 
			}
		}
	printf("hit: %d, miss: %d\n", hit, miss);
	return 0;
}							


