#include "main.h"

/**
 * swap_char - swaps | and & for non-printed chars
 *
 * @valeur: valeur string
 * @check: type of swap
 * Return: swapped string
 */
char *swap_char(char *valeur, int check)
{
	int i;

	if (check == 0)
	{
		for (i = 0; valeur[i]; i++)
		{
			if (valeur[i] == '|')
			{
				if (valeur[i + 1] != '|')
					valeur[i] = 16;
				else
					i++;
			}

			if (valeur[i] == '&')
			{
				if (valeur[i + 1] != '&')
					valeur[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; valeur[i]; i++)
		{
			valeur[i] = (valeur[i] == 16 ? '|' : valeur[i]);
			valeur[i] = (valeur[i] == 12 ? '&' : valeur[i]);
		}
	}
	return (valeur);
}

/**
 * aj_noeuds - add separators and command lines in the lists
 *
 * @dividor_head: head 
 * @linehead: head cmdline
 * @valeur: valeur string
 */
void aj_noeuds(list_separator **dividor_head,
		store_line **linehead, char *valeur)
{
	int i;
	char *line;

	valeur = swap_char(valeur, 0);

	for (i = 0; valeur[i]; i++)
	{
		if (valeur[i] == ';')
			separator_list(dividor_head, valeur[i]);

		if (valeur[i] == '|' || valeur[i] == '&')
		{
			separator_list(dividor_head, valeur[i]);
			i++;
		}
	}

	line = _strtok(valeur, ";|&");
	do {
		line = swap_char(line, 1);
		aj_ligne(linehead, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * suivant - next cmdline
 * @seplist: list dividor
 * @linelist: command line list
 * @nodesh: nodestore
 */
void suivant(list_separator **seplist, store_line **linelist, node_sh *nodesh)
{
	int boucle_sep;
	list_separator *list_se;
	store_line *list_le;

	boucle_sep = 1;
	list_se = *seplist;
	list_le = *linelist;

	while (list_se != NULL && boucle_sep)
	{
		if (nodesh->status == 0)
		{
			if (list_se->dividor == '&' || list_se->dividor == ';')
				boucle_sep = 0;
			if (list_se->dividor == '|')
				list_le = list_le->next, list_se = list_se->next;
		}
		else
		{
			if (list_se->dividor == '|' || list_se->dividor == ';')
				boucle_sep = 0;
			if (list_se->dividor == '&')
				list_le = list_le->next, list_se = list_se->next;
		}
		if (list_se != NULL && !boucle_sep)
			list_se = list_se->next;
	}

	*seplist = list_se;
	*linelist = list_le;
}

/**
 * split_commands - this divides command lines
 * @nodesh: node value
 * @valeur: valeur string
 *
 * Return: 0 (exit) or 1
 */
int split_commands(node_sh *nodesh, char *valeur)
{

	list_separator *dividor_head, *seplist;
	store_line *linehead, *linelist;
	int boucle;

	dividor_head = NULL;
	linehead = NULL;

	aj_noeuds(&dividor_head, &linehead, valeur);

	seplist = dividor_head;
	linelist = linehead;

	while (linelist != NULL)
	{
		nodesh->input = linelist->cmd_line;
		nodesh->args = split_line(nodesh->input);
		boucle = execute_line(nodesh);
		free(nodesh->args);

		if (boucle == 0)
			break;

		suivant(&seplist, &linelist, nodesh);

		if (linelist != NULL)
			linelist = linelist->next;
	}

	free_dividor(&dividor_head);
	line_free(&linehead);

	if (boucle == 0)
		return (0);
	return (1);
}

/**
 * split_line - put values in array
 * @valeur: valeur string.
 *
 * Return: string into array.
 */
char **split_line(char *valeur)
{
	size_t taiile;
	size_t i;
	char **jetons;
	char *token;

	taiile = SIZEOF_TOKBUF;
	jetons = malloc(sizeof(char *) * (taiile));
	if (jetons == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(valeur, TK_DELIM);
	jetons[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == taiile)
		{
			taiile += SIZEOF_TOKBUF;
			jetons = _realloc_v2(jetons, i, sizeof(char *) * taiile);
			if (jetons == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TK_DELIM);
		jetons[i] = token;
	}

	return (jetons);
}
