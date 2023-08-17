#include "stringfun.h"

/**
 * reverse_str - this function aims to reverse a string.
 * @str: this parameter represents the string to reverse.
 */
void reverse_str(char *str)
{
	int cpt, x, y;
	char *chaine, temp;

	for (cpt = 0; cpt >= 0; cpt++)
	{
		if (str[cpt] == '\0')
			break;
	}
	chaine = str;

	for (x = 0; x < (cpt - 1); x++)
	{
		for (y = x + 1; y > 0; y--)
		{
			temp = *(chaine + y);
			*(chaine + y) = *(chaine + (y - 1));
			*(chaine + (y - 1)) = temp;
		}
	}
}

/**
 * _strcat - this function aims to concatanate two strings
 * @dest: The destination string (end result).
 * @src: The started string or the source.
 *
 * Return: the concatanated string.
 */
char *_strcat(char *dest, const char *src)
{
	/* Code goes here */
}
