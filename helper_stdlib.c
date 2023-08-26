#include "main.h"

/**
 * get_longu - recupere la longuueur du mot.
 * @n: nombre
 * Return: retourne le nombre
 */
int get_longu(int n)
{
	unsigned int n1;
	int longught = 1;

	if (n < 0)
	{
		longught++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		longught++;
		n1 = n1 / 10;
	}

	return (longught);
}
/**
 * helper_itoa - convertis entier en nombre.
 * @n: nombre
 * Return: chaine
 */
char *helper_itoa(int n)
{
	unsigned int n1;
	int longught = get_longu(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (longught + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + longught) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	longught--;
	do {
		*(buffer + longught) = (n1 % 10) + '0';
		n1 = n1 / 10;
		longught--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converti chaine en entier.
 * @s: entree.
 * Return: entier.
 */
int _atoi(char *s)
{
	unsigned int count = 0, taille = 0, ro = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (taille > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (taille > 0)
				m *= 10;
			taille++;
		}
		count++;
	}

	for (i = count - taille; i < count; i++)
	{
		ro = ro + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (ro * pn);
}
