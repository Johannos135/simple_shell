#include "main.h"

/**
 * _sigint_g - allows ctrl + c
 * @s: param signal
 */
void _sigint_g(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n$ ", 3);
}
