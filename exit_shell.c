#include "main.h"

/**
 * exit_shell - exits the shell
 *
 * @nodesh: donnee soit status, soit args
 * Return: 0 si vrai
 */
int exit_shell(node_sh *nodesh)
{
	unsigned int ustatus;
	int is_digit;
	int str_longu;
	int big_number;

	if (nodesh->args[1] != NULL)
	{
		ustatus = _atoi(nodesh->args[1]);
		is_digit = _isdigit(nodesh->args[1]);
		str_longu = _strlongu(nodesh->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_longu > 10 || big_number)
		{
			get_err(nodesh, 2);
			nodesh->status = 2;
			return (1);
		}
		nodesh->status = (ustatus % 256);
	}
	return (0);
}
