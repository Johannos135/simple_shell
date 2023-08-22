#include "memoryhandler.h"

/**
 * _memcpy - this function aims to copy data in src in dest
 * in the heap
 * @destination: this paramter will store datz coming from src.
 * @source: this parameter is the storage of the main data.
 * @len: defines the length of dest
 */
void _memcpy(void *destination, const void *source, unsigned int len)
{
	unsigned int count = 0;
	char *ptr_src = (char *)source;
	char *ptr_dest = (char *)destination;

	while (count < len)
	{
		ptr_dest[count] = ptr_src[count];
		count++;
	}
}
