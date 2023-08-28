#include "main.h"

/**
 * add_sep_node_end - ajoute un separateur a la fin
 * du noeud
 * @entete: entete en debut de noeud
 * @sep: separateur trouve (; | &).
 * Return: address of sep.
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
 * free_div_list - libere la liste des sep
 * @entete: entete du noeud
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
 * add_ldanse_node_end - ajoute une commande a la
 * fin de la ligne
 * @entete: entete du noeud
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
 * free_ligne - libere une ligne
 * @entete: entete de la ligne
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
