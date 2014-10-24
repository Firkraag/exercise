int test(int x, int y) {
	int val = x - y;
	
	if (x < -3) {
		if (x > y) 
			val = x * y;
		else
			val = x + y;
	} else if (x <= 2)
		val = x ^ y;
	return val;
}
