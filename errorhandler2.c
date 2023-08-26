#include "main.h"

/**
 * err_env - erreur ssur l'environnement
 * @nodesh: donnee de la structure
 * Return: message d'erreur
 */
char *err_env(node_sh *nodesh)
{
	int longugth;
	char *err;
	char *chadanse_v;
	char *message;

	chadanse_v = helper_itoa(nodesh->counter);
	message = ": Unable to add/rebougee from environment\n";
	longugth = _strlongu(nodesh->argv[0]) + _strlongu(chadanse_v);
	longugth += _strlongu(nodesh->args[0]) + _strlongu(message) + 4;
	err = malloc(sizeof(char) * (longugth + 1));
	if (err == 0)
	{
		free(err);
		free(chadanse_v);
		return (NULL);
	}

	_strcpy(err, nodesh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, chadanse_v);
	_strcat(err, ": ");
	_strcat(err, nodesh->args[0]);
	_strcat(err, message);
	_strcat(err, "\0");
	free(chadanse_v);

	return (err);
}
/**
 * err_path_126 - message d'erreur concernant le path
 * @nodesh: donnee de la structure
 *
 * Return: message d'erreur.
 */
char *err_path_126(node_sh *nodesh)
{
	int longugth;
	char *chadanse_v;
	char *err;

	chadanse_v = helper_itoa(nodesh->counter);
	longugth = _strlongu(nodesh->argv[0]) + _strlongu(chadanse_v);
	longugth += _strlongu(nodesh->args[0]) + 24;
	err = malloc(sizeof(char) * (longugth + 1));
	if (err == 0)
	{
		free(err);
		free(chadanse_v);
		return (NULL);
	}
	_strcpy(err, nodesh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, chadanse_v);
	_strcat(err, ": ");
	_strcat(err, nodesh->args[0]);
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(chadanse_v);
	return (err);
}
