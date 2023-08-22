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
	int count1 = 0, count2 = 0;
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

/**
 * _longueur - this function aims to return a number's length.
 * @number: this parameter represents the number to count.
 *
 * Return: an integer as total length.
 */
int _longueur(int number)
{
	int num, s = 1;

	if (number < 0)
	{
		s = s + 1;
		num = number * (-1);
	}
	else
		num = number;
	while (num > 9)
	{
		s = s + 1;
		num /= 10;
	}
	return (s);
}

/**
 * _itoa - this function aims to transform an integer to a string.
 * @number: this parameter represents the number to be converted.
 *
 * Return: the number in string format.
 */
char *_itoa(int number)
{
	unsigned int num;
	char *event;
	int sizeof_num = _longueur(number);

	event = malloc(sizeof(char) * (sizeof_num + 1));
	if (event == 0)
		return (NULL);
	*(event + sizeof_num) = '\0';

	if (number < 0)
	{
		num = number * (-1);
		event[0] = '-';
	}
	else
		num = number;
	sizeof_num--;

	while (num > 0)
	{
		*(event + sizeof_num) = (num % 10) + '0';
		num /= 10;
		sizeof_num--;
	}
	return (event);
}

/**
 * _atoi - is the opposite of _itoa it transforms a str into an integer.
 * @str: string parameter to be converted.
 *
 * Return: a new value as integer.
 */
int _atoi(char *str)
{
	unsigned int cpt_a = 0, cpt_b = 0, sizeof_num = 0;
	unsigned int val1 = 0, val2 = 1, val3 = 1;

	while (str[cpt_a] != '\0')
	{
		if (sizeof_num > 0 && (str[cpt_a] < '0' || str[cpt_a] > '9'))
			break;
		if (str[cpt_a] == '-')
			val2 = val2 * (-1);
		if (str[cpt_a] >= '0' && (str[cpt_a] <= '9'))
		{
			if (sizeof_num > 0)
				val3 = val3 * 10;
			sizeof_num = sizeof_num + 1;
		}
		cpt_a++;
	}

	cpt_b = cpt_a - sizeof_num;

	while (cpt_b < cpt_a)
	{
		val1 = val1 + ((str[cpt_b] - 48) * val3);
		val3 = val3 / 10;
		cpt_b++;
	}
	return (val1 * val2);
}
