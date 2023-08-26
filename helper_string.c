#include "main.h"

/**
 * _strcat - concatenate deux chaines
 * @dest: onfere destination
 * @src: confere source
 * Return: cahine concate
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcpy - copie la chaine
 * @dest: confere destination
 * @src: confere source
 * Return: chaine copie
 */
char *_strcpy(char *dest, char *src)
{

	size_t valeur;

	for (valeur = 0; src[valeur] != '\0'; valeur++)
	{
		dest[valeur] = src[valeur];
	}
	dest[valeur] = '\0';

	return (dest);
}
/**
 * _strcmp - comparateur de chaine
 * @strdansg1: chaine 1
 * @strdansg2: chaine 2
 * Return: Always 0.
 */
int _strcmp(char *strdansg1, char *strdansg2)
{
	int i;

	for (i = 0; strdansg1[i] == strdansg2[i] && strdansg1[i]; i++)
		;

	if (strdansg1[i] > strdansg2[i])
		return (1);
	if (strdansg1[i] < strdansg2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - retrouve chaine
 * @s: strdansg.
 * @c: caractère.
 * Return: pointer sur valeur.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - recuperes sous chaine.
 * @s: valeur initial.
 * @accept: accepteur de byte.
 * Return:nombre d'octet
 */
int _strspn(char *s, char *accept)
{
	int i, j, checker;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		checker = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				checker = 0;
				break;
			}
		}
		if (checker == 1)
			break;
	}
	return (i);
}
