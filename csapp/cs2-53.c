#include <stdio.h>	
//#define POS_INFINITY 1.8e308 * 10.0 //0x7ff0000000000000
//#define NEG_INFINITY 1.8e308 * (-10.0) //0xfff0000000000000
//#define POS_INFINITY 1.0e400
//#define NEG_INFINITY 1.0e400
#define POS_INFINITY  1 /  0.0
#define NEG_INFINITY  1 / -0.0
#define NEG_ZERO     -0.0 //0x8000000000000000

int main() {
	double x = NEG_ZERO;
	double pos_inf = POS_INFINITY;
	double neg_inf = NEG_INFINITY;

	show_double(x);
	show_double(pos_inf);
	show_double(neg_inf);
	printf("%f, %f, %f\n", POS_INFINITY, NEG_INFINITY, NEG_ZERO);

}
