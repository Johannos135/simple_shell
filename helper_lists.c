#include "main.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a div_list.
 * @entete: entete of the ldansked list.
 * @sep: separator found (; | &).
 * Return: address of the entete.
 */
div_list *add_sep_node_end(div_list **entete, char sep)
{
	div_list *new, *temp;

	new = malloc(sizeof(div_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *entete;

	if (temp == NULL)
	{
		*entete = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*entete);
}

/**
 * free_div_list - frees a div_list
 * @entete: entete of the ldansked list.
 * Return: no return.
 */
void free_div_list(div_list **entete)
{
	div_list *temp;
	div_list *curr;

	if (entete != NULL)
	{
		curr = *entete;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*entete = NULL;
	}
}

/**
 * add_ldanse_node_end - adds a command ldanse at the end
 * of a ligne.
 * @entete: entete of the ldansked list.
 * @ldanse: command ldanse.
 * Return: address of the entete.
 */
ligne *add_ldanse_node_end(ligne **entete, char *ldanse)
{
	ligne *new, *temp;

	new = malloc(sizeof(ligne));
	if (new == NULL)
		return (NULL);

	new->ldanse = ldanse;
	new->next = NULL;
	temp = *entete;

	if (temp == NULL)
	{
		*entete = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*entete);
}

/**
 * free_ligne - frees a ligne
 * @entete: entete of the ldansked list.
 * Return: no return.
 */
void free_ligne(ligne **entete)
{
	ligne *temp;
	ligne *curr;

	if (entete != NULL)
	{
		curr = *entete;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*entete = NULL;
	}
}
