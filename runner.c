#include "main.h"

/**
 * sans_comment - deletes comments from the entree
 *
 * @dans: entree strdansg
 * Return: entree sans comments
 */
char *sans_comment(char *dans)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; dans[i]; i++)
	{
		if (dans[i] == '#')
		{
			if (i == 0)
			{
				free(dans);
				return (NULL);
			}

			if (dans[i - 1] == ' ' || dans[i - 1] == '\t' || dans[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		dans = _realloc(dans, i, up_to + 1);
		dans[up_to] = '\0';
	}

	return (dans);
}

/**
 * shell_boucle - Loop of shell
 * @nodesh: donnee relevant (argv, entree, args)
 *
 * Return: no return.
 */
void shell_boucle(node_sh *nodesh)
{
	int boucle, fin_v;
	char *entree;

	boucle = 1;
	while (boucle == 1)
	{
		write(STDIN_FILENO, "$ ", 2);
		entree = read_ldanse(&fin_v);
		if (fin_v != -1)
		{
			entree = sans_comment(entree);
			if (entree == NULL)
				continue;

			if (check_syntax_err(nodesh, entree) == 1)
			{
				nodesh->status = 2;
				free(entree);
				continue;
			}
			entree = repart_variable(entree, nodesh);
			boucle = splitter_commands(nodesh, entree);
			nodesh->counter += 1;
			free(entree);
		}
		else
		{
			boucle = 0;
			free(entree);
		}
	}
}
