#include "main.h"

/**
 * _help_g - this function retrieves helper
 * @nodesh: node value
 *
 * Return: 1 (Success)
*/
int _help_g(node_sh *nodesh)
{

	if (nodesh->args[1] == 0)
		general_info();
	else if (_strcmp(nodesh->args[1], "setenv") == 0)
		setenv_helper();
	else if (_strcmp(nodesh->args[1], "env") == 0)
		environ_helper();
	else if (_strcmp(nodesh->args[1], "unsetenv") == 0)
		unsetenv_helper();
	else if (_strcmp(nodesh->args[1], "exit") == 0)
		exit_helper();
	else
		write(STDERR_FILENO, nodesh->args[0],
		      _strlen(nodesh->args[0]));

	nodesh->status = 0;
	return (1);
}
