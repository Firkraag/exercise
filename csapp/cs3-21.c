int loop_while(int a, int b) {
	int result = 1;

	if (a >= b)
		goto done;
    
	int add = a + b;
loop:
	result *= add;
	add++;
	a++;
	if (a < b)
		goto loop;
done:
	return result;
}
