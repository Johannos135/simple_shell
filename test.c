#include <stdio.h>
#include "string_fun.h"

/**
 * main - Entry point
 *
 * Return: 0(Success)
 */
int main(void)
{
	char *val = "435";

	if (_isdigit(val))
		printf("I am a string\n");
	else
		printf("Not a string\n");

	return (0);
}
