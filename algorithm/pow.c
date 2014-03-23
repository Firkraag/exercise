/* pow: comput x^n; return value: x ^ n */
int pow1(int x, unsigned n) {
	if (n == 0)
		return 1;
	if (n % 2)
		return pow1(x * x, n/2) * x;
	else
		return pow1(x * x, n/2);
}

