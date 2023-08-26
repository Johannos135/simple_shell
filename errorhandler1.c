#include "main.h"

/**
 * strcat_changed - message d'erreur sur la concat de changed
 *
 * @nodesh: donnee de la structure
 * @message: message a afficher
 * @err: sortie erreur
 * @chadanse_v: compteur de ligne
 * Return: message d'erreur
 */
char *strcat_changed(node_sh *nodesh, char *message, char *err, char *chadanse_v)
{
	char *illegal_flag;

	_strcpy(err, nodesh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, chadanse_v);
	_strcat(err, ": ");
	_strcat(err, nodesh->args[0]);
	_strcat(err, message);
	if (nodesh->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = nodesh->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(err, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(err, nodesh->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/**
 * err_get_changed - message d'erreur sur get_changed
 * @nodesh: donnee de la structure
 * Return: message d'erreur
 */
char *err_get_changed(node_sh *nodesh)
{
	int longugth, longu_id;
	char *err, *chadanse_v, *message;

	chadanse_v = helper_itoa(nodesh->counter);
	if (nodesh->args[1][0] == '-')
	{
		message = ": Illegal option ";
		longu_id = 2;
	}
	else
	{
		message = ": can't changed to ";
		longu_id = _strlongu(nodesh->args[1]);
	}

	longugth = _strlongu(nodesh->argv[0]) + _strlongu(nodesh->args[0]);
	longugth += _strlongu(chadanse_v) + _strlongu(message) + longu_id + 5;
	err = malloc(sizeof(char) * (longugth + 1));

	if (err == 0)
	{
		free(chadanse_v);
		return (NULL);
	}

	err = strcat_changed(nodesh, message, err, chadanse_v);

	free(chadanse_v);

	return (err);
}

/**
 * err_not_found - message d'erreur non trouve
 * @nodesh: donnee de la structure
 * Return: message d'erreur
 */
char *err_not_found(node_sh *nodesh)
{
	int longugth;
	char *err;
	char *chadanse_v;

	chadanse_v = helper_itoa(nodesh->counter);
	longugth = _strlongu(nodesh->argv[0]) + _strlongu(chadanse_v);
	longugth += _strlongu(nodesh->args[0]) + 16;
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
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(chadanse_v);
	return (err);
}

/**
 * err_exit_shell - message de la structure
 * @nodesh: donnee de la structure
 *
 * Return: message d'erreur
 */
char *err_exit_shell(node_sh *nodesh)
{
	int longugth;
	char *err;
	char *chadanse_v;

	chadanse_v = helper_itoa(nodesh->counter);
	longugth = _strlongu(nodesh->argv[0]) + _strlongu(chadanse_v);
	longugth += _strlongu(nodesh->args[0]) + _strlongu(nodesh->args[1]) + 23;
	err = malloc(sizeof(char) * (longugth + 1));
	if (err == 0)
	{
		free(chadanse_v);
		return (NULL);
	}
	_strcpy(err, nodesh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, chadanse_v);
	_strcat(err, ": ");
	_strcat(err, nodesh->args[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, nodesh->args[1]);
	_strcat(err, "\n\0");
	free(chadanse_v);

	return (err);
}
