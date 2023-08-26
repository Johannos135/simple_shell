#include "main.h"

/**
 * read_ldanse - reads the entree strdansg.
 *
 * @fin_v: return value of getline function
 * Return: entree strdansg
 */
char *read_ldanse(int *fin_v)
{
	char *entree = NULL;
	size_t bufsize = 0;

	*fin_v = getline(&entree, &bufsize, stdin);

	return (entree);
}
