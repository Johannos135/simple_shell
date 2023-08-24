#include "main.h"

/**
 * swap_info - makes a copy information in alliases
 * @name: argument name
 * @value: argument value
 *
 * Return: return alias.
 */
char *swap_info(char *name, char *value)
{
	char *add;
	int sizof_el_name, sizof_el_value, sizof_el;

	sizof_el_name = _strlen(name);
	sizof_el_value = _strlen(value);
	sizof_el = sizof_el_name + sizof_el_value + 2;
	add = malloc(sizeof(char) * (sizof_el));
	_strcpy(add, name);
	_strcat(add, "=");
	_strcat(add, value);
	_strcat(add, "\0");

	return (add);
}

/**
 * set_env - setter of env name
 * @name: argument name
 * @value: argument value
 * @nodesh: node value
 */
void set_env(char *name, char *value, node_sh *nodesh)
{
	int i;
	char *environ_varv, *environ_nom;

	for (i = 0; nodesh->_environment[i]; i++)
	{
		environ_varv = _strdup(nodesh->_environment[i]);
		environ_nom = _strtok(environ_varv, "=");
		if (_strcmp(environ_nom, name) == 0)
		{
			free(nodesh->_environment[i]);
			nodesh->_environment[i] = swap_info(environ_nom, value);
			free(environ_varv);
			return;
		}
		free(environ_varv);
	}

	nodesh->_environment = _realloc_v2(nodesh->_environment, i,
			sizeof(char *) * (i + 2));
	nodesh->_environment[i] = swap_info(name, value);
	nodesh->_environment[i + 1] = NULL;
}

/**
 * _setenv - makes comparison betwenn environ names
 * @nodesh: node value
 * Return: 1 (Success).
 */
int _setenv(node_sh *nodesh)
{

	if (nodesh->args[1] == NULL || nodesh->args[2] == NULL)
	{
		_error_g(nodesh, -1);
		return (1);
	}

	set_env(nodesh->args[1], nodesh->args[2], nodesh);

	return (1);
}

/**
 * _unsetenv - this function aims to remove env var
 * @nodesh: node value
 *
 * Return: 1 (Success).
 */
int _unsetenv(node_sh *nodesh)
{
	char **env_rea;
	char *environ_varv, *environ_nom;
	int i, j, k;

	if (nodesh->args[1] == NULL)
	{
		_error_g(nodesh, -1);
		return (1);
	}
	k = -1;
	for (i = 0; nodesh->_environment[i]; i++)
	{
		environ_varv = _strdup(nodesh->_environment[i]);
		environ_nom = _strtok(environ_varv, "=");
		if (_strcmp(environ_nom, nodesh->args[1]) == 0)
		{
			k = i;
		}
		free(environ_varv);
	}
	if (k == -1)
	{
		_error_g(nodesh, -1);
		return (1);
	}
	env_rea = malloc(sizeof(char *) * (i));
	for (i = j = 0; nodesh->_environment[i]; i++)
	{
		if (i != k)
		{
			env_rea[j] = nodesh->_environment[i];
			j++;
		}
	}
	env_rea[j] = NULL;
	free(nodesh->_environment[k]);
	free(nodesh->_environment);
	nodesh->_environment = env_rea;
	return (1);
}
