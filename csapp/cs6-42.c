#include <stdio.h>
#include <math.h>

typedef struct {
		int valid;
		int check;
	} LINE;
int main() {
	int size = 1 << 14;
	LINE line[1 << 14];
	unsigned int i, j;
	unsigned int start_addr = 0x0;
	unsigned int addr;
	unsigned set;
	unsigned check;
	int miss = 0, hit = 0;
	for (i = 0; i < size; i++)
		(line[i]).valid = 0;
	for (j = 0; j < 640; j++) 
		for (i = 0; i < 480; i++) {
			printf("i: %d, j: %d  ", i, j);
			addr = start_addr + i * 4 * 640 + j * 4;
			set = (addr & 0xfffc) >> 2;
			check = (addr & 0xffff0000) >> 16;
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
			addr = addr + 1;
			set = (addr & 0xfffc) >> 2;
			check = (addr & 0xffff0000) >> 16;
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
			addr = addr + 1;
			set = (addr & 0xfffc) >> 2;
			check = (addr & 0xffff0000) >> 16;
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
			addr = addr + 1;
			set = (addr & 0xfffc) >> 2;
			check = (addr & 0xffff0000) >> 16;
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


