#include "main.h"

/**
 * provide_line - this provide cmdline to getline
 * @ptrptr_cmd: point to cmdline
 * @buffer: buf string
 * @n: size of line
 * @sizeof_b: taille du buffer
 */
void provide_line(char **ptrptr_cmd, size_t *n, char *buffer, size_t sizeof_b)
{

	if (*ptrptr_cmd == NULL)
	{
		if  (sizeof_b > SIZEOF_BUF)
			*n = sizeof_b;

		else
			*n = SIZEOF_BUF;
		*ptrptr_cmd = buffer;
	}
	else if (*n < sizeof_b)
	{
		if (sizeof_b > SIZEOF_BUF)
			*n = sizeof_b;
		else
			*n = SIZEOF_BUF;
		*ptrptr_cmd = buffer;
	}
	else
	{
		_strcpy(*ptrptr_cmd, buffer);
		free(buffer);
	}
}
/**
 * get_line - reader in stream
 * @ptrptr_cmd: cmd storage
 * @n: size of ptrptr_cmd
 * @stream: total stream
 *
 * Return: total bytes
 */
ssize_t get_line(char **ptrptr_cmd, size_t *n, FILE *stream)
{
	int i;
	static ssize_t value;
	ssize_t val_return;
	char *buffer;
	char temp = 'z';

	if (value == 0)
		fflush(stream);
	else
		return (-1);
	value = 0;

	buffer = malloc(sizeof(char) * SIZEOF_BUF);
	if (buffer == 0)
		return (-1);
	while (temp != '\n')
	{
		i = read(STDIN_FILENO, &temp, 1);
		if (i == -1 || (i == 0 && value == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && value != 0)
		{
			value++;
			break;
		}
		if (value >= SIZEOF_BUF)
			buffer = _realloc(buffer, value, value + 1);
		buffer[value] = temp;
		value++;
	}
	buffer[value] = '\0';
	provide_line(ptrptr_cmd, n, buffer, value);
	val_return = value;
	if (i != 0)
		value = 0;
	return (val_return);
}
