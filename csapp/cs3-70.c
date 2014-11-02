typedef struct ELE *tree_ptr;
struct ELE {
	tree_ptr left;
	tree_ptr right;
	long val;
};

long traverse(tree_ptr tp) {
	long int val = 0x7fffffffffffffff;
	
	if (tp) {
		long int node_value = tp->val;
		long int left_value = traverse(tp->left);
		long int right_value = traverse(tp->right);
		val = left_value <= right_value ? left_value : right_value;
		if (node_value < val)
			val = node_value;
	} 
	return val;
}
