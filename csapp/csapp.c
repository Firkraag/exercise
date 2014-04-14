#include <stdio.h>
#include <string.h>
#include <math.h>


typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len) {
        int i;

        for (i = 0; i < len; i++)
	        printf(" %.2x", start[i]);
        printf("\n");
}
void show_int(int x) { 
	show_bytes((byte_pointer) &x, sizeof(int)); 
} 
void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}
void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}
void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}
void show_long(long x) {
        show_bytes((byte_pointer) &x, sizeof(long));
} 
void show_double(double x) {
        show_bytes((byte_pointer) &x, sizeof(double));
}
void test_show_bytes(int val) {
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}
int fun1(unsigned word) {
	return (int) ((word << 24) >> 24);
}
int fun2(unsigned word) {
	return ((int) word << 24) >> 24;
}
float sum_elements(float a[], unsigned length) {
	int i;
	float result = 0;

	for ( i = 0; i <= length-1; i++)
		result += a[i];
	return result;
}
int strlonger(char *s, char *t) {
	return strlen(s) > strlen(t) ;
}
int uadd_ok(unsigned short x, unsigned short y) {
	unsigned short sum = x+y;
	return sum >= x;
}
// Determine whether arguments can be added without overflow 
short tadd_ok(short x, short y) {
	short sum = x+y;
	short neg_over = x < 0 && y < 0 && sum >= 0;
	short pos_over = x >= 0 && y >= 0 && sum < 0;
	return !neg_over && !pos_over;
}
int is_big_endian(void) {
	int i = 1;
	return i != ((byte_pointer) &i)[0];
}
unsigned put_byte(unsigned x, unsigned char b, int i) {
	unsigned y;
	int l;
	for(l = 0;l < sizeof(unsigned); l++) {
		if (l != i)
			((byte_pointer) &y)[l] = ((byte_pointer) &x)[l];
		else  ((byte_pointer) &y)[l] = b;
	}
	printf("0x%x\n", y);
}
unsigned replace_byte (unsigned x, int i, unsigned char b) {
	int itimes8 = i << 3;
	unsigned mask = 0xFF << itimes8;
	return (x & ~mask) | (b << itimes8);
}

