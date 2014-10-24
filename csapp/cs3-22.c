int fun_a(unsigned x) {
	int val = 0;

	while (x) {
		val ^= x;
		x >>= 1;
	}
	return val & 1;
}

