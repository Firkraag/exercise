#include <stdio.h>

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

float power(float base, int n)
{
	int i;
	float p;

	p = 1.0;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}

int main() {
	float x = 5.0;
	int i = 10;
	float d = power(2.0, 126);

	for (x = 5.0; x < 10000.0; x += 100.0)
		show_float(x);
	printf("\n");
	printf("%f\n", d);
	//for (d = 5.0; d < 10000.0; d += 100.0)
	//	show_double(d);
	show_float(d);
}
