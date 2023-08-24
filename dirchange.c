#include "main.h"

/**
 * change_current - this function allows to
 * change the current directory
 *
 * @nodesh: node value
 * Return: returns 1 if OK
 */
int change_current(node_sh *nodesh)
{
	char *directory;
	int acc1, acc2, ishyphen;

	directory = nodesh->args[1];

	if (directory != NULL)
	{
		acc1 = _strcmp("$HOME", directory);
		acc2 = _strcmp("~", directory);
		ishyphen = _strcmp("--", directory);
	}

	if (directory == NULL || !acc1 || !acc2 || !ishyphen)
	{
		changed_to_home(nodesh);
		return (1);
	}

	if (_strcmp("-", directory) == 0)
	{
		changed_previous(nodesh);
		return (1);
	}

	if (_strcmp(".", directory) == 0 || _strcmp("..", directory) == 0)
	{
		changed_dot(nodesh);
		return (1);
	}

	changed_to(nodesh);

	return (1);
}
