#include "main.h"

/**
 * separator_list - this function adsds a separator to a list node
 * @entete: header of the node.
 * @separator: separator symbol
 *
 * Return: header address
 */
list_separator *separator_list(list_separator **entete, char separator)
{
	list_separator *add, *swap;

	add = malloc(sizeof(list_separator));

	if (add == NULL)
		return (NULL);

	add->dividor = separator;
	add->next = NULL;
	swap = *entete;

	if (swap == NULL)
		*entete = add;
	else
	{
		while (swap->next != NULL)
			swap = swap->next;
		swap->next = add;
	}
	return (*entete);
}

/**
 * free_dividor - this function frees our dividor or separator
 * @entete: header of the node
 */
void free_dividor(list_separator **entete)
{
	list_separator *swap;
	list_separator *value;

	if (entete != NULL)
	{
		value = *entete;

		while ((swap = value) != NULL)
		{
			value = value->next;
			free(swap);
		}
		*entete = NULL;
	}
}

/**
 * aj_ligne - this function adds a new command at the end of node
 * @entete: header of the node
 * @cmdline: represents the command line
 *
 * Return: node address
 */
store_line *aj_ligne(store_line **entete, char *cmdline)
{
	store_line *add, *swap;

	add = malloc(sizeof(store_line));

	if (add == NULL)
	{
		return (NULL);
	}

	add->cmd_line = cmdline;
	add->next = NULL;
	swap = *entete;

	if (swap == NULL)
	{
		*entete = add;
	}
	else
	{
		while (swap->next != NULL)
			swap = swap->next;
		swap->next = add;
	}

	return (*entete);
}

/**
 * line_free - this function frees the entire node
 * @entete: header of node
 */
void line_free(store_line **entete)
{
	store_line *swap, *value;

	if (entete != NULL)
	{
		value = *entete;

		while ((swap = value) != NULL)
		{
			value = value->next;
			free(swap);
		}
		*entete = NULL;
	}
}
