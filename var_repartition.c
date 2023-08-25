#include "main.h"

/**
 * environ_checker - environment var checker
 *
 * @h: header
 * @in: value to enter
 * @nodesh: nodesh value
 */
void environ_checker(store_var **h, char *in, node_sh *nodesh)
{
	int row, param, cpt, left_value;
	char **nvl_env;

	nvl_env = nodesh->_environ;
	for (row = 0; nvl_env[row]; row++)
	{
		for (cpt = 1, param = 0; nvl_env[row][param]; param++)
		{
			if (nvl_env[row][param] == '=')
			{
				left_value = _strlen(nvl_env[row] + param + 1);
				aj_var(h, cpt, nvl_env[row] + param + 1, left_value);
				return;
			}

			if (in[cpt] == nvl_env[row][param])
				cpt++;
			else
				break;
		}
	}

	for (cpt = 0; in[cpt]; cpt++)
	{
		if (in[cpt] == ' ' || in[cpt] == '\t' || in[cpt] == ';' || in[cpt] == '\n')
			break;
	}

	aj_var(h, cpt, NULL, 0);
}

/**
 * variable_checkers - check $$ or $?
 *
 * @entete: head of the linked list
 * @value: this param represents value
 * @etat: last status
 * @nodesh: node value
 *
 * Return: position index
 */
int variable_checkers(store_var **entete, char *value,
		char *etat, node_sh *nodesh)
{
	int last_int, pd_param, cpt = 0;

	last_int = _strlen(etat);
	pd_param = _strlen(nodesh->pid);

	while (value[cpt])
	{
		if (value[cpt] == '$')
		{
			if (value[cpt + 1] == '?')
				aj_var(entete, 2, etat, last_int), cpt++;
			else if (value[cpt + 1] == '$')
				aj_var(entete, 2, nodesh->pid, pd_param), cpt++;
			else if (value[cpt + 1] == '\n')
				aj_var(entete, 0, NULL, 0);
			else if (value[cpt + 1] == '\0')
				aj_var(entete, 0, NULL, 0);
			else if (value[cpt + 1] == ' ')
				aj_var(entete, 0, NULL, 0);
			else if (value[cpt + 1] == '\t')
				aj_var(entete, 0, NULL, 0);
			else if (value[cpt + 1] == ';')
				aj_var(entete, 0, NULL, 0);
			else
				environ_checker(entete, value + cpt, nodesh);
		}
		cpt++;
	}

	return (cpt);
}

/**
 * val_replacement - this variable is used to replace variable
 *
 * @head: entete
 * @value: this represents value param
 * @new_value: new string value
 * @sizeof_n: new size of value
 * Return: new value
 */
char *val_replacement(store_var **head, char *value,
		char *new_value, int sizeof_n)
{
	store_var *indice;
	int i, cpt, k;

	indice = *head;
	for (cpt = i = 0; i < sizeof_n; i++)
	{
		if (value[cpt] == '$')
		{
			if (!(indice->sizeof_var) && !(indice->sizeof_val))
			{
				new_value[i] = value[cpt];
				cpt++;
			}
			else if (indice->sizeof_var && !(indice->sizeof_val))
			{
				for (k = 0; k < indice->sizeof_var; k++)
					cpt++;
				i--;
			}
			else
			{
				for (k = 0; k < indice->sizeof_val; k++)
				{
					new_value[i] = indice->value[k];
					i++;
				}
				cpt += (indice->sizeof_var);
				i--;
			}
			indice = indice->next;
		}
		else
		{
			new_value[i] = value[cpt];
			cpt++;
		}
	}

	return (new_value);
}

/**
 * var_replacement - var replacement
 *
 * @value: value string
 * @nodeshsh: nodesh value
 * Return: var remplacement
 */
char *var_replacement(char *value, node_sh *nodeshsh)
{
	store_var *head, *indice;
	char *status, *new_value;
	int sizeof_val, sizeof_n;

	status = cus_itoa(nodeshsh->status);
	head = NULL;

	sizeof_val = variable_checkers(&head, value, status, nodeshsh);

	if (head == NULL)
	{
		free(status);
		return (value);
	}

	indice = head;
	sizeof_n = 0;

	while (indice != NULL)
	{
		sizeof_n += (indice->sizeof_val - indice->sizeof_var);
		indice = indice->next;
	}

	sizeof_n += sizeof_val;

	new_value = malloc(sizeof(char) * (sizeof_n + 1));
	new_value[sizeof_n] = '\0';

	new_value = val_replacement(&head, value, new_value, sizeof_n);

	free(value);
	free(status);
	variable_free(&head);

	return (new_value);
}
