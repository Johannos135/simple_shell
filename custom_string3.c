#include "stringfun.h"

/**
 * _strspn - this tells the length of a string consisting
 * entirely of the set of characters in accept set.
 * @str: the string used for searching
 * @value: the list (string like) of accepted characters.
 *
 * Return: the length of the greatest substring.
 */
int _strspn(char *str, char *value)
{
	int count1 = 0, int count2 = 0;
	int check;

	while (str[count1] != '\0')
	{
		check = 1;

		while (value[count2] != '\0')
		{
			if (str[count1] == value[count2])
			{
				check = 0;
				break;
			}
			count2++;
		}
		if (check == 1)
			break;
		count1++;
	}
	return (count1);
}
