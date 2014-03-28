/* Do rotating right shift. Assume 0 <= n < w
Examples when x = 0x12345678 and w = 32;
	n = 4 -> 0x81234567, n = 20 -> 0x45678123
*/

unsigned rotate_right(unsigned x, int n) {
	unsigned y = x >> n;

	x = (x << (32 - n - 1)) << 1;
	return x | y;
}
