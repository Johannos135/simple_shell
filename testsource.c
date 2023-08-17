#include "stringfun.h"
#include "template.h"

/**
 * main - Entry point
 * Return: 0 (Success)
 */
int main(void)
{
	char hello[6] = "Hello";
	int i;

	reverse_str(hello);

	for (; hello[i] != '\0'; i++)
		putchar(hello[i]);
	putchar('\n');

	return (0);
}


