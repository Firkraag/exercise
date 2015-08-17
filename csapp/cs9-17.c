#include "csapp.h"

// We also have to update next_fit_start in function mm_free in case the block next_fit_start points to no longer exists after free
static void *next_fit_start = (void *) heap_listp + DSIZE;
static void *next_fit(size_t asize)
{
	void *bp = next_fit_start;
	size_t size;

	do {
		size = GET_SIZE(HDRP(bp));
		if (size >= asize && !GET_ALLOC(HDRP(bp)))
		{
			next_fit_start = bp;
			return bp;
		}
		if (size == 0)
		{
			bp == heap_listp + DSIZE;
		}
		else
			bp = NEXT_BLKP(bp);
	}	while (bp != next_fit_start)
	return NULL;
}
