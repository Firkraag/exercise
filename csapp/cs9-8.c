#include "csapp.h"

static void *find_fit(size_t asize)
{
	void *hdr = heap_histp + WSIZE;
	size_t size;

	while ((size = GET_SIZE(hdr)) != 0)
	{
		if (size >= asize && !GET_ALLOC(hdr))
			return hdr + WSIZE;
		hdr += size;
	}
	return NULL;
}
