int pow1(int x, unsigned n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n % 2)
		return (pow1(x*x, n/2) * x);
	else 
		return (pow1(x*x, n/2));
}
