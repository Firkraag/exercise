typedef struct {
	int coeff_array[MAX_DEGREE + 1];
	unsigned int high_power;
} *POLYNOMIAL;
typedef struct node *node_ptr;
struct node {
	int coefficient;
	int exponent;
	node_ptr next;
};
typedef node_ptr POLYNOMIAL;	/* keep nodes sorted by exponent */
void zero_polynomial(POLYNOMIAL poly) {
	unsigned int i;
	for (i = 0; i <= MAX_DEGREE; i++) 
		poly->coeff_array[i] = 0;
	poly->high_power = 0;
}
void add_polynomial(POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_sum) {
	int i;
	zero_polynomial(poly_sum);
	poly_sum->high_power = max(poly1->high_power, poly2->high_power);
	for (i = poly_sum->high_power; i>=0; i--)
		poly_sum->coeff_array[i] = poly1->coeff_array[i] + poly2->coeff_array[i];
}
void mult_polynomial(POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_prod) {
	unsigned int i, j;
	zero_polynomial(poly_prod);
	poly_prod->high_power = poly1->high_power + poly2->high_power;
	if (poly_prod->high_power > MAX_DEGREE)
		error("Exceeded array size");
	else 
		for (i = 0; i <= poly1->high_power;i++)
			for (j = 0;j <= poly2->high_power; j++)
				poly_prod->coeff_array[i+j] += poly1->coeff_array[i] * poly2->coeff_array[j];
}
void add_polynomial(POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_sum) {
} 
	
