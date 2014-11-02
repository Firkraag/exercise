struct prob {
	int *p;
	struct {
		int x;
		int y;
	} s;
	struct prob *next;
};

void sp_init(struct prob *sp) {
	sp->s.x = sp->s.y;
	sp->p   = &(sp->s.x);
	sp->next = sp;
}
