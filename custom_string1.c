#include "stringfun.h"

/**
 * _strlen - this function return the length of a string.
 * @str: this parameter represents the input string.
 *
 * Return: the value to be return is the length of the string.
 */
int _strlen(const char *str)
{
	int count = 0;

	while (str[count] != '\0')
		count++;

	return (count);
}

/**
 * _isdigit - te purpose of this function is to tell if the input is a number.
 * @str: this parameter represents the input string.
 *
 * Return: two possible values (0 or 1).
 */
int _isdigit(const char *str)
{
	unsigned int count = 0;

	while (str[count])
	{
		if (str[count] < 48 || str[count] > 57)
			return (0);

		count++;
	}

	return (1);
}

/**
 * _strdup - the purpose of this function is to duplicate
 * a string in the main memory (heap)
 *
 * @str: this parameter represents the input string
 * Return: A clone of the string
 */
char *_strdup(const char *str)
{
	char *clone;
	size_t length;

	length = _strlen(str);
	clone = malloc(sizeof(char) * (length + 1));

	if (clone == NULL)
		return (NULL);

	_memcpy(clone, str, (length + 1));

	return (clone);
}

/**
 * compare_char - this function aims to compare all the characters of a string
 * @str: pointer string as input.
 * @delimiter: max char number.
 *
 * Return: two possible values 1 or 0.
 */
int compare_char(char *str, const char *delimiter)
{
	unsigned int x, y, z;

	for (x = 0, z = 0; str[x]; x++)
	{
		for (y = 0; delimiter[y]; y++)
		{
			if (str[x] == delimiter[y])
			{
				z++;
				break;
			}
		}
	}

	if (x == z)
		return (1);

	return (0);
}

/**
 * _strtok - takes a string and a delimiter and break it into serie of words.
 * @str: represents the string to be transformed into words.
 * @delimiter: represents the delimiter character or symbol.
 *
 * Return: serie of words.
 */
char *_strtok(char *str, const char *delimiter)
{
	static char *words, *last_word;
	char *first_word;
	unsigned int count, b;

	if (str != NULL)
	{
		if (compare_char(str, delimiter))
			return (NULL);
		words = str;
		count = _strlen(str);
		last_word = &str[i];
	}

	first_word = words;

	if (first_word == last_word)
		return (NULL);

	for (b = 0; *words; words++)
	{
		if (words != first_word)
			if (*words && *(words - 1) == '\0')
				break;

		for (count = 0; delimiter[count]; count++)
		{
			if (*words == delimiter[i])
			{
				*words = '\0';

				if (words == first_word)
					first_word++;
				break;
			}
		}

		if (b == 0 && *words)
			b = 1;
	}

	if (b == 0)
		return (NULL);
	return (first_word);
}
