#include "main.h"

/**
 * copy_dansfo - copies dansfo to create
 * a new env or alias
 * @nom: nom (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_dansfo(char *nom, char *value)
{
	char *new;
	int longu_nom, longu_value, longu;

	longu_nom = _strlongu(nom);
	longu_value = _strlongu(value);
	longu = longu_nom + longu_value + 2;
	new = malloc(sizeof(char) * (longu));
	_strcpy(new, nom);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @nom: nom of the environment variable
 * @value: value of the environment variable
 * @nodesh: donnee structure (environ)
 * Return: no return
 */
void set_env(char *nom, char *value, node_sh *nodesh)
{
	int i;
	char *var_env, *nom_env;

	for (i = 0; nodesh->_environ[i]; i++)
	{
		var_env = _strdup(nodesh->_environ[i]);
		nom_env = _strtok(var_env, "=");
		if (_strcmp(nom_env, nom) == 0)
		{
			free(nodesh->_environ[i]);
			nodesh->_environ[i] = copy_dansfo(nom_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	nodesh->_environ = _reallochangedp(nodesh->_environ, i, sizeof(char *) * (i + 2));
	nodesh->_environ[i] = copy_dansfo(nom, value);
	nodesh->_environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables noms
 * with the nom passed.
 * @nodesh: donnee relevant (env nom and env value)
 *
 * Return: 1 on success.
 */
int _setenv(node_sh *nodesh)
{

	if (nodesh->args[1] == NULL || nodesh->args[2] == NULL)
	{
		get_err(nodesh, -1);
		return (1);
	}

	set_env(nodesh->args[1], nodesh->args[2], nodesh);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @nodesh: donnee relevant (env nom)
 *
 * Return: 1 on success.
 */
int _unsetenv(node_sh *nodesh)
{
	char **realloc_environ;
	char *var_env, *nom_env;
	int i, j, k;

	if (nodesh->args[1] == NULL)
	{
		get_err(nodesh, -1);
		return (1);
	}
	k = -1;
	for (i = 0; nodesh->_environ[i]; i++)
	{
		var_env = _strdup(nodesh->_environ[i]);
		nom_env = _strtok(var_env, "=");
		if (_strcmp(nom_env, nodesh->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_err(nodesh, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; nodesh->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = nodesh->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(nodesh->_environ[k]);
	free(nodesh->_environ);
	nodesh->_environ = realloc_environ;
	return (1);
}
