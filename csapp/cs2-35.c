/* Determine whether arguments can be multiplied without overflow */
/* When overflow, return 0; otherwise return 1 */
int tmul_ok(int x, int y) {
	int p = x * y;
	
	return !x || (p / x == y);
}
