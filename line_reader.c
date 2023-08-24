#include "main.h"

/**
 * read_line - value reader.
 *
 * @in_value: return getline val
 * Return: return value
 */
char *read_line(int *in_value)
{
	char *value = NULL;
	size_t sizeof_buffer = 0;

	*in_value = getline(&value, &sizeof_buffer, stdin);

	return (value);
}
