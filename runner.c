#include "main.h"

/**
 * cmt_remove - deletes comments from the input
 *
 * @value: value of input
 * Return: remove comment in input
 */
char *cmt_remove(char *value)
{
	int i, jusqua;

	jusqua = 0;
	for (i = 0; value[i]; i++)
	{
		if (value[i] == '#')
		{
			if (i == 0)
			{
				free(value);
				return (NULL);
			}

			if (value[i - 1] == ' ' || value[i - 1] == '\t' || value[i - 1] == ';')
				jusqua = i;
		}
	}

	if (jusqua != 0)
	{
		value = _realloc(value, i, jusqua + 1);
		value[jusqua] = '\0';
	}

	return (value);
}

/**
 * runner - shell runner
 * @nodesh: node value
 */
void runner(node_sh *nodesh)
{
	int boucle, return_input;
	char *input;

	boucle = 1;
	while (boucle == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		input = read_line(&return_input);
		if (return_input != -1)
		{
			input = cmt_remove(input);
			if (input == NULL)
				continue;

			if (syntax_verify(nodesh, input) == 1)
			{
				nodesh->status = 2;
				free(input);
				continue;
			}
			input = var_replacement(input, nodesh);
			boucle = split_commands(nodesh, input);
			nodesh->cpt += 1;
			free(input);
		}
		else
		{
			boucle = 0;
			free(input);
		}
	}
}
