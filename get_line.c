#include "main.h"

/**
 * provide_ldanse - affecte la ligne
 * @ldanseptr: buffer pour stocker les entrees
 * @buffer: chaine à afficher
 * @n: taille de l'entree
 * @j: taille du buffer
 */
void provide_ldanse(char **ldanseptr, size_t *n, char *buffer, size_t j)
{

	if (*ldanseptr == NULL)
	{
		if  (j > TAILLEBUF)
			*n = j;

		else
			*n = TAILLEBUF;
		*ldanseptr = buffer;
	}
	else if (*n < j)
	{
		if (j > TAILLEBUF)
			*n = j;
		else
			*n = TAILLEBUF;
		*ldanseptr = buffer;
	}
	else
	{
		_strcpy(*ldanseptr, buffer);
		free(buffer);
	}
}
/**
 * get_ldanse - lire la var
 * @ldanseptr: stockage du buffer
 * @n: taille de s
 * @stream: flux d'entree
 * Return: retourne le nombre de bit
 */
ssize_t get_ldanse(char **ldanseptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t entree;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (entree == 0)
		fflush(stream);
	else
		return (-1);
	entree = 0;

	buffer = malloc(sizeof(char) * TAILLEBUF);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && entree == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && entree != 0)
		{
			entree++;
			break;
		}
		if (entree >= TAILLEBUF)
			buffer = _realloc(buffer, entree, entree + 1);
		buffer[entree] = t;
		entree++;
	}
	buffer[entree] = '\0';
	provide_ldanse(ldanseptr, n, buffer, entree);
	retval = entree;
	if (i != 0)
		entree = 0;
	return (retval);
}
