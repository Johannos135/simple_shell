#include "main.h"

/**
 * _memcpy - this function aims to copy data in src in dest
 * in the heap
 * @destination: this paramter will store datz coming from src.
 * @source: this parameter is the storage of the main data.
 * @len: defines the length of dest
 */
void _memcpy(void *destination, const void *source, unsigned int len)
{
	unsigned int count;
	char *ptr_src = (char *)source;
	char *ptr_dest = (char *)destination;

	for (count = 0; count < len; count++)
	{
		ptr_dest[count] = ptr_src[count];
	}
}

/**
 * _realloc - attemps to resize the memory block pointed to by src.
 * @src: this is a pointer to a memory block previously allocated.
 * @sizeof_src: size of the pointer previously allocated.
 * @sizeof_dest: this is new size for the memory block.
 *
 * Return: the reallocated value.
 */
void *_realloc(void *src, unsigned int sizeof_src, unsigned int sizeof_dest)
{
	void *block_new;

	if (src == NULL)
		return (malloc(sizeof_dest));
	if (sizeof_dest == 0)
	{
		free(src);
		return (NULL);
	}
	if (sizeof_dest == sizeof_src)
		return (src);

	block_new = malloc(sizeof_dest);

	if (block_new == NULL)
		return (NULL);

	if (sizeof_dest < sizeof_src)
		_memcpy(block_new, src, sizeof_dest);
	else
		_memcpy(block_new, src, sizeof_src);
	free(src);
	return (block_new);
}

/**
 * _realloc_v2 - attemps to resize the memory block double pointed to by src.
 * @src: this is a pointer to a memory block previously allocated.
 * @sizeof_src: size of the pointer previously allocated.
 * @sizeof_dest: this is new size for the memory block.
 *
 * Return: the reallocated value.
 */
char **_realloc_v2(char **src, unsigned int sizeof_src,
		unsigned int sizeof_dest)
{
	char **block_new;
	unsigned int count;

	if (src == NULL)
		return (malloc(sizeof(char *) * sizeof_dest));

	if (sizeof_dest == sizeof_src)
		return (src);

	block_new = malloc(sizeof(char *) * sizeof_dest);

	if (block_new == NULL)
		return (NULL);

	for (count = 0; count < sizeof_src; count++)
	{
		block_new[count] = src[count];
	}
	free(src);
	return (block_new);
}
