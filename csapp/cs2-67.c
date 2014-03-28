#include <stdio.h>

//int bad_int_size_is_32() {
	///* Set most significant bit (msb) of 32-bit machine */
	//int set_msb = 1 << 31;
	///* Shift past msb of 32-bit word */
	//int beyond_msb = 1 << 32;
//
	//printf("%x\n", beyond_msb);	
	///* set_msb is nonzero when word size >= 32
		//beyond_msb is zero when word size <= 32 */
	//return set_msb && !beyond_msb;
//}
//Write a procedure int_size_is_32() that yields 1 when run on a machine forwhich an int is 32 bits, and yields 0 otherwise
//Run properly on any machine for which data type int is at least 32 bits
int int_size_is_32() {
	return !!(((1 << 31) >> 31) ^ 1); 
}

//Run properly on any machine for which data type int is at least 16 bits
int int_size_is_32_16() {
	int left_shift = ((1 << 15) << 15) << 1;
	int right_shift = ((left_shift >> 15) >> 15) >> 1;

	return (right_shift != 1) && (right_shift != 0);
}

main() {
	printf("%d\n", int_size_is_32_16());
}
