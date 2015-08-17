
/* work for ascii, save space*/
int isupper1(int c) {
	if (c >= 'A' && c <= 'Z')
		return 1;
	else
		return 0;
}

/* save time */
int isupper2(int c) {
	switch (c) {
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		return 1;
	default:
		return 0;
	}
}
