#include "main.h"

/**
 * aj_rv_node - adds a variable at the end
 * of a store_var list.
 * @entete: entete of the ldansked list.
 * @lvar: longugth of the variable.
 * @val: value of the variable.
 * @lval: longugth of the value.
 * Return: address of the entete.
 */
store_var *aj_rv_node(store_var **entete, int lvar, char *val, int lval)
{
	store_var *new, *temp;

	new = malloc(sizeof(store_var));
	if (new == NULL)
		return (NULL);

	new->longu_var = lvar;
	new->val = val;
	new->longu_val = lval;

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
 * lib_rv_list - frees a store_var list
 * @entete: entete of the ldansked list.
 * Return: no return.
 */
void lib_rv_list(store_var **entete)
{
	store_var *temp;
	store_var *curr;

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
