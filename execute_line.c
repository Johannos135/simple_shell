#include "main.h"

/**
 * execute_line - this function execute a cmdline
 * @nodesh: node value
 * Return: 1 (Success).
 */
int execute_line(node_sh *nodesh)
{
	int (*builtin_ptr)(node_sh *nodesh);

	if (nodesh->args[0] == NULL)
		return (1);

	builtin_ptr = _builtin_g(nodesh->args[0]);

	if (builtin_ptr != NULL)
		return (builtin_ptr(nodesh));

	return (execute_cmd(nodesh));
}

/**
 * quit_shell - this function is used to take out  shell
 *
 * @nodesh: node value
 * Return: 0 (Success).
 */
int quit_shell(node_sh *nodesh)
{
	unsigned int etat;
	int est_chiffre;
	int longueur_ch;
	int biginteger;

	if (nodesh->args[1] != NULL)
	{
		etat = _atoi(nodesh->args[1]);
		est_chiffre = _isdigit(nodesh->args[1]);
		longueur_ch = _strlen(nodesh->args[1]);
		biginteger = etat > (unsigned int)INT_MAX;

		if (!est_chiffre || longueur_ch > 10 || biginteger)
		{
			_error_g(nodesh, 2);
			nodesh->status = 2;
			return (1);
		}
		nodesh->status = (etat % 256);
	}
	return (0);
}

/**
 * _builtin_g - retrieves all the builtins
 * @cmd: input value as command
 *
 * Return: returns builtins
 */
int (*_builtin_g(char *cmd))(node_sh *)
{
	builtins builtin[] = {
		{ "env", _env },
		{ "exit", quit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", change_current },
		{ "help", _help_g },
		{ NULL, NULL }
	};
	int count = 0;

	while (builtin[count].name)
	{
		if (_strcmp(builtin[count].name, cmd) == 0)
			break;
		count++;
	}

	return (builtin[count].fonction);
}
