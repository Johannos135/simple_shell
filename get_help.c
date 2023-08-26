#include "main.h"

/**
 * get_help - recupere les messages d'aide
 * @nodesh: nouvelle structure
 * Return: Return 1
*/
int get_help(node_sh *nodesh)
{

	if (nodesh->args[1] == 0)
		helper1_general();
	else if (_strcmp(nodesh->args[1], "setenv") == 0)
		helper1_setenv();
	else if (_strcmp(nodesh->args[1], "env") == 0)
		helper1_env();
	else if (_strcmp(nodesh->args[1], "unsetenv") == 0)
		helper1_unsetenv();
	else if (_strcmp(nodesh->args[1], "help") == 0)
		helper1();
	else if (_strcmp(nodesh->args[1], "exit") == 0)
		helper1_exit();
	else if (_strcmp(nodesh->args[1], "changed") == 0)
		helper1_changed();
	else if (_strcmp(nodesh->args[1], "alias") == 0)
		helper1_alias();
	else
		write(STDERR_FILENO, nodesh->args[0],
		      _strlongu(nodesh->args[0]));

	nodesh->status = 0;
	return (1);
}
