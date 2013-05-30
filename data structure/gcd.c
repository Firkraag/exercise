unsigned gcd(unsigned m, unsigned n) {
	unsigned rem;
	while (n > 0) {
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;
}
