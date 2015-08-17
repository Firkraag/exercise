#include <stdio.h>
typedef long Align;

union header {
	struct {
		union header *ptr;
		unsigned size;
	} s;
	Align x;
};
typedef union header Header;

static Header base;
static Header *freep = NULL;

void free(void *ap) {
	Header *bp, *p;

	bp = (Header *) ap - 1;
	if (bp->s.size == 0)
		return;
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break;
	if (bp + bp->s.size == p->s.ptr) {
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr  =  p->s.ptr->s.ptr;
	}
	else
		bp->s.ptr = p->s.ptr;
	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;
		p->s.ptr   = bp->s.ptr;
	}
	else
		p->s.ptr = bp;
	freep = p;
}

void *bfree(void *p, unsigned n) {
	Header *ptr = (Header *) p;

	if (p == NULL)
		return NULL;
	if (n <= sizeof(Header)) {
		fprintf(stderr, "The size must be greater than %lu\n", sizeof(Header));
		return NULL;
	}		
	if (n % sizeof(Header)) {
		fprintf(stderr, "The size must be multiply of %lu\n", sizeof(Header));
		return NULL;
	}
	ptr->s.size = n / sizeof(Header);
	if (freep == NULL) {
		base.s.ptr = freep = &base;
		base.s.size = 1;
	}
	free(ptr + 1);
	return p;
}
