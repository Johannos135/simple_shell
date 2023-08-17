#include "stringfun.h"

/**
 * main - Entry point
 * Return: 0 (Success)
 */
int main(void)
{
    char dest[40] = "Welcome to ";
    char src[] = "Alice world";
    //Append src in dest
    char *hello = _strcat(dest, src);
    int i;

	for (i = 0; hello[i] != '\0'; i++)
		putchar(hello[i]);
	putchar('\n');

	return (0);
}


