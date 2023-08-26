#include "main.h"

/**
 * get_err - fait appel au message d'erreur
 * @nodesh: donnee de la struct
 * @eval: valeur d'erreur
 * Return: code de l'erreur
 */
int get_err(node_sh *nodesh, int eval)
{
	char *err;

	switch (eval)
	{
	case -1:
		err = err_env(nodesh);
		break;
	case 126:
		err = err_path_126(nodesh);
		break;
	case 127:
		err = err_not_found(nodesh);
		break;
	case 2:
		if (_strcmp("exit", nodesh->args[0]) == 0)
			err = err_exit_shell(nodesh);
		else if (_strcmp("changed", nodesh->args[0]) == 0)
			err = err_get_changed(nodesh);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlongu(err));
		free(err);
	}

	nodesh->status = eval;
	return (eval);
}
