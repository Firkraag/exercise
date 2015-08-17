#include "csapp.h"

static void *place(void *bp, size_t asize)
{
	size_t freeblock_size = GETSIZE(HDRP(bp));
	size_t remainder_size = freeblock_size - asize;

	if (remain_size >= 2 * DSIZE)
	{
		PUT(HDRP(bp), PACK(asize, 1));
		PUT(FTRP(bp), PACK(asize, 1));
		PUT(HDRP(NEXT_BLKP(bp)), PACK(remainder_size, 0));
		PUT(FTRP(NEXT_BLKP(bp)), PACK(remainder_size, 0));
	}
	else
	{
		PUT(HDRP(bp), PACK(freeblock_size, 1);
		PUT(FTRP(bp), PACK(freeblock_size, 1);
	}
	return;
}
