union ele {
	struct {
		int *p;
		int x;
	} e1;
	struct {
		int y;
		union ele *next;
	} e2;
};

void proc(union ele *up) {
	up->e2.next->e1.x = *(up->e2.next->e1.p) - up->e2.y;
}
