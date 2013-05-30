#include <stdio.h>

typedef unsigned INDEX;

INDEX hash1(char *key, unsigned H_SIZE) {
	unsigned hash_val = 0;
	
	while ( *key != '\0')
		hash_val += *key++;
	return hash_val % H_SIZE;
}
INDEX hash2(char *key, unsigned H_SIZE) {
	return (key[0] + 27 * key[1] + 729 * key[2]) % H_SIZE;
}
INDEX hash3(char *key, unsigned H_SIZE) {
	unsigned hash_val = 0;

	while (*key != '\0')
		hash_val = (hash_val << 5) + *key++;
	return hash_val * H_SIZE;
}
