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
	int count1 = 0, count2 = 0;

	if (dest == NULL && src == NULL)
		return (NULL);

	while (dest[count1] != '\0')
		count1++;

	while (src[count2] != '\0')
	{
		dest[count1] = src[count2];
		count1++;
		count2++;
	}
	dest[count1] = '\0';

	return (dest);
}

/**
 * _strcpy - this function aims to copy a string in src into dest.
 * @dest: represents the destination parameter (the target).
 * @src: represents the characters to be copied.
 *
 * Return: the characters copied.
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';

	return (dest);
}

/**
 * _strcmp - this function aims to compare str1 and str2.
 * @str1: first string to be compared.
 * @str2: second one.
 *
 * Return: 0 if true.
 */
int _strcmp(char *str1, char *str2)
{
	int count = 0;

	while (str1[count] == str2[count] && str1[count])
		count++;

	if (str1[count] > str2[count])
		return (1);

	if (str1[count] < str2[count])
		return (-1);

	return (0);
}

/**
 * _strchr - this function allows us to find the first instance
 *  of a character in a string
 *  @str: represents the entire string.
 *  @character: instance of the character to find.
 *
 *  Return: the first instance of the chaeacter.
 */
char *_strchr(char *str, char character)
{
	int count = 0;

	while (*(str + count) != '\0')
	{
		if (*(str + count) == character)
		{
			return (str + count);
		}
		count++;
	}

	if (*(str + count) == character)
		return (str + character);
	return ('\0');
}
