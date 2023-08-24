#include "main.h"

/**
 * _error_g - returns error value
 * @nodesh: node argument values
 * @err_value: parameter err_value
 *
 * Return: error value
 */
int _error_g(node_sh *nodesh, int err_value)
{
	char *error;

	switch (err_value)
	{
	case -1:
		error = environ_error(nodesh);
		break;
	case 126:
		error = path_err(nodesh);
		break;
	case 127:
		error = error404(nodesh);
		break;
	case 2:
		if (_strcmp("exit", nodesh->args[0]) == 0)
			error = exit_error(nodesh);
		else if (_strcmp("cd", nodesh->args[0]) == 0)
			error = directory_err(nodesh);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	nodesh->status = err_value;
	return (err_value);
}
