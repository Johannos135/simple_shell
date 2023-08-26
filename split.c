#include "main.h"

/**
 * swap_char - ange| and & pour nn imprimable
 * @entree: entree chaine
 * @checker: vleur echange
 * Return: chaine echange
 */
char *swap_char(char *entree, int checker)
{
	int i;

	if (checker == 0)
	{
		for (i = 0; entree[i]; i++)
		{
			if (entree[i] == '|')
			{
				if (entree[i + 1] != '|')
					entree[i] = 16;
				else
					i++;
			}

			if (entree[i] == '&')
			{
				if (entree[i + 1] != '&')
					entree[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; entree[i]; i++)
		{
			entree[i] = (entree[i] == 16 ? '|' : entree[i]);
			entree[i] = (entree[i] == 12 ? '&' : entree[i]);
		}
	}
	return (entree);
}

/**
 * add_nodes - joute noeuds
 * @entete_s: entete of separator list
 * @entete_l: entete of command ldanses list
 * @entree: entree strdansg
 */
void add_nodes(div_list **entete_s, ligne **entete_l, char *entree)
{
	int i;
	char *ldanse;

	entree = swap_char(entree, 0);

	for (i = 0; entree[i]; i++)
	{
		if (entree[i] == ';')
			add_sep_node_end(entete_s, entree[i]);

		if (entree[i] == '|' || entree[i] == '&')
		{
			add_sep_node_end(entete_s, entree[i]);
			i++;
		}
	}

	ldanse = _strtok(entree, ";|&");
	do {
		ldanse = swap_char(ldanse, 1);
		add_ldanse_node_end(entete_l, ldanse);
		ldanse = _strtok(NULL, ";|&");
	} while (ldanse != NULL);

}

/**
 * go_next - va au suivant
 *
 * @list_s: separator list
 * @list_l: command ldanse list
 * @nodesh: donnee structure
 */
void go_next(div_list **list_s, ligne **list_l, node_sh *nodesh)
{
	int boucle_sep;
	div_list *ls_s;
	ligne *ls_l;

	boucle_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && boucle_sep)
	{
		if (nodesh->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				boucle_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				boucle_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !boucle_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * splitter_commands - separe en tranche
 * @nodesh: donnee structure
 * @entree: entree strdansg
 * Return: 0 en sortie
 */
int splitter_commands(node_sh *nodesh, char *entree)
{

	div_list *entete_s, *list_s;
	ligne *entete_l, *list_l;
	int boucle;

	entete_s = NULL;
	entete_l = NULL;

	add_nodes(&entete_s, &entete_l, entree);

	list_s = entete_s;
	list_l = entete_l;

	while (list_l != NULL)
	{
		nodesh->entree = list_l->ldanse;
		nodesh->args = splitter_ldanse(nodesh->entree);
		boucle = exec_ldanse(nodesh);
		free(nodesh->args);

		if (boucle == 0)
			break;

		go_next(&list_s, &list_l, nodesh);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_div_list(&entete_s);
	free_ligne(&entete_l);

	if (boucle == 0)
		return (0);
	return (1);
}

/**
 * splitter_ldanse - transforme entree en jeton
 * @entree: entree strdansg.
 * Return: chaine tronquer.
 */
char **splitter_ldanse(char *entree)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_TAILLEBUF;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation err\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(entree, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_TAILLEBUF;
			tokens = _reallochangedp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation err\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
