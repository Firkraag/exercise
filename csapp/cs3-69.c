typedef struct ELE *tree_ptr;
struct ELE {
	tree_ptr left;
	tree_ptr right;
	long val;
};

long trace(tree_ptr tp) {
	long val = 0L;

	while (tp) {
		val = tp->val;
		tp = tp->left;
	}
	return val;
}
