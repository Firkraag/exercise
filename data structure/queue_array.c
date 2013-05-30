#include "queue_array.h"

int is_empty(QUEUE Q) {
	return Q->q_size == 0;
}
void make_null(QUEUE Q) {
	Q->q_size = 0;
	Q->q_front = 1;
	Q->q_rear = 0;
}
unsigned succ(unsigned value, QUEUE Q) {
	if (++value == Q->q_max_size)
		value = 0;
	return value;
}
void enqueue(element_type x, QUEUE Q) {
	if (if_full(Q))
		error("Full queue");
	else {
		Q->q_size++;
		Q->q_rear = succ(Q->q_rear, Q);
		Q->q_array[Q->q_rear] = x;
	}
}
