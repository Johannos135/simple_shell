#include "main.h"

/**
 * aj_var - this function adds a variable at the node's end
 * @entete: header of node
 * @lng_var: sizeof the variable
 * @value: represents our variable value
 * @lng_val: represents our value's length
 *
 * Return: node address
 */
store_var *aj_var(store_var **entete, int lng_var,
		char *value, int lng_val)
{
	store_var *add, *swap;

	add = malloc(sizeof(store_var));

	if (add == NULL)
		return (NULL);

	add->sizeof_var = lng_var;
	add->value = value;
	add->sizeof_val = lng_val;
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
 * variable_free - this function aims to free up variable nodes
 * @entete: header of node
 */
void variable_free(store_var **entete)
{
	store_var *swap, *add;

	if (entete != NULL)
	{
		add = *entete;

		while ((swap = add) != NULL)
		{
			add = add->next;
			free(swap);
		}
		*entete = NULL;
	}
}
