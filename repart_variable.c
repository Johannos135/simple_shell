#include "main.h"

/**
 * environ_checker - checks if the typed variable is an env variable
 *
 * @h: entete of ldansked list
 * @dans: entree strdansg
 * @donnee: donnee structure
 * Return: no return
 */
void environ_checker(store_var **h, char *dans, node_sh *donnee)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = donnee->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _strlongu(_envr[row] + chr + 1);
				aj_rv_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (dans[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; dans[j]; j++)
	{
		if (dans[j] == ' ' || dans[j] == '\t' || dans[j] == ';' || dans[j] == '\n')
			break;
	}

	aj_rv_node(h, j, NULL, 0);
}

/**
 * check_vars - check if the typed variable is $$ or $?
 *
 * @h: entete of the ldansked list
 * @dans: entree strdansg
 * @st: last status of the Shell
 * @donnee: donnee structure
 * Return: no return
 */
int check_vars(store_var **h, char *dans, char *st, node_sh *donnee)
{
	int i, lst, lpd;

	lst = _strlongu(st);
	lpd = _strlongu(donnee->pid);

	for (i = 0; dans[i]; i++)
	{
		if (dans[i] == '$')
		{
			if (dans[i + 1] == '?')
				aj_rv_node(h, 2, st, lst), i++;
			else if (dans[i + 1] == '$')
				aj_rv_node(h, 2, donnee->pid, lpd), i++;
			else if (dans[i + 1] == '\n')
				aj_rv_node(h, 0, NULL, 0);
			else if (dans[i + 1] == '\0')
				aj_rv_node(h, 0, NULL, 0);
			else if (dans[i + 1] == ' ')
				aj_rv_node(h, 0, NULL, 0);
			else if (dans[i + 1] == '\t')
				aj_rv_node(h, 0, NULL, 0);
			else if (dans[i + 1] == ';')
				aj_rv_node(h, 0, NULL, 0);
			else
				environ_checker(h, dans + i, donnee);
		}
	}

	return (i);
}

/**
 * replaced_entree - replaces strdansg into variables
 *
 * @entete: entete of the ldansked list
 * @entree: entree strdansg
 * @new_entree: new entree strdansg (replaced)
 * @lon: new longugth
 * Return: replaced strdansg
 */
char *replaced_entree(store_var **entete, char *entree, char *new_entree, int lon)
{
	store_var *dansdice;
	int i, j, k;

	dansdice = *entete;
	for (j = i = 0; i < lon; i++)
	{
		if (entree[j] == '$')
		{
			if (!(dansdice->longu_var) && !(dansdice->longu_val))
			{
				new_entree[i] = entree[j];
				j++;
			}
			else if (dansdice->longu_var && !(dansdice->longu_val))
			{
				for (k = 0; k < dansdice->longu_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < dansdice->longu_val; k++)
				{
					new_entree[i] = dansdice->val[k];
					i++;
				}
				j += (dansdice->longu_var);
				i--;
			}
			dansdice = dansdice->next;
		}
		else
		{
			new_entree[i] = entree[j];
			j++;
		}
	}

	return (new_entree);
}

/**
 * repart_variable - calls functions to replace strdansg into vars
 *
 * @entree: entree strdansg
 * @nodesh: donnee structure
 * Return: replaced strdansg
 */
char *repart_variable(char *entree, node_sh *nodesh)
{
	store_var *entete, *dansdice;
	char *status, *new_entree;
	int olongu, lon;

	status = helper_itoa(nodesh->status);
	entete = NULL;

	olongu = check_vars(&entete, entree, status, nodesh);

	if (entete == NULL)
	{
		free(status);
		return (entree);
	}

	dansdice = entete;
	lon = 0;

	while (dansdice != NULL)
	{
		lon += (dansdice->longu_val - dansdice->longu_var);
		dansdice = dansdice->next;
	}

	lon += olongu;

	new_entree = malloc(sizeof(char) * (lon + 1));
	new_entree[lon] = '\0';

	new_entree = replaced_entree(&entete, entree, new_entree, lon);

	free(entree);
	free(status);
	lib_rv_list(&entete);

	return (new_entree);
}
