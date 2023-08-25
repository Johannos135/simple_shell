#include "main.h"

/**
 * compare_namev - this function compares env_var names
 * @name_environ: environment name argument
 * @name: argument name
 *
 * Return: 0 (not equal)
 */
int compare_namev(const char *name_environ, const char *name)
{
	int i = 0;

	while (name_environ[i] != '=')
	{
		if (name_environ[i] != name[i])
		{
			return (0);
		}
		i++;
	}

	return (i + 1);
}

/**
 * _getenv - this function retrieves environment variable
 * @name: argv name
 * @_environ: argument of environment variable
 *
 * Return: returns env_variable.
 */
char *_getenv(const char *name, char **_environ)
{
	char *point_venv;
	int deplace, count;

	point_venv = NULL;
	deplace = 0;
	count = 0;

	while (_environ[count])
	{
		deplace = compare_namev(_environ[count], name);
		if (deplace)
		{
			point_venv = _environ[count];
			break;
		}
		count++;
	}

	return (point_venv + deplace);
}

/**
 * _env - display the evironment variables
 *
 * @nodesh: node value
 * Return: 1 (Success).
 */
int _env(node_sh *nodesh)
{
	int count1, count2;

	for (count1 = 0; nodesh->_environ[count1]; count1++)
	{

		for (count2 = 0; nodesh->_environ[count1][count2]; count2++)
			;

		write(STDOUT_FILENO, nodesh->_environ[count1], count2);
		write(STDOUT_FILENO, "\n", 1);
	}
	nodesh->status = 0;

	return (1);
}
