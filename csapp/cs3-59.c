int switch_prob(int x, int n) {
	int result = x;

	switch(n) {
	case 28:
	case 30:
		result <<= 3;
		break;
	case 31:
		result >>= 3;
		break;
	case 32:
		result *= 7;
	case 33:
		result *= result;
	default:
		result += 11;
	}
	return result;
}
