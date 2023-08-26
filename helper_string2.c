#include "main.h"

/**
 * _strdup - duplicates a str dans the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s)
{
	char *new;
	size_t longu;

	longu = _strlongu(s);
	new = malloc(sizeof(char) * (longu + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, longu + 1);
	return (new);
}

/**
 * _strlongu - Returns the longught of a strdansg.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _strlongu(const char *s)
{
	int longu;

	for (longu = 0; s[longu] != 0; longu++)
	{
	}
	return (longu);
}

/**
 * cmp_chars - compare chars of strdansgs
 * @str: entree strdansg.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splitters a strdansg by some delimiter.
 * @str: entree strdansg.
 * @delim: delimiter.
 *
 * Return: strdansg splittered.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitterted, *str_end;
	char *str_start;
	unsigned int i, checker;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitterted = str; /*Store first address*/
		i = _strlongu(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = splitterted;
	if (str_start == str_end) /*Reachdansg the end*/
		return (NULL);

	for (checker = 0; *splitterted; splitterted++)
	{
		/*Breakdansg boucle fdansddansg the next token*/
		if (splitterted != str_start)
			if (*splitterted && *(splitterted - 1) == '\0')
				break;
		/*Replachangedansg delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitterted == delim[i])
			{
				*splitterted = '\0';
				if (splitterted == str_start)
					str_start++;
				break;
			}
		}
		if (checker == 0 && *splitterted) /*Str != Delim*/
			checker = 1;
	}
	if (checker == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defdanses if strdansg passed is a number
 *
 * @s: entree strdansg
 * Return: 1 if strdansg is a number. 0 dans other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
