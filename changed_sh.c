#include "main.h"

/**
 * changed_shell - changes current directory
 *
 * @nodesh: donnee relevant
 * Return: 1 on success
 */
int changed_shell(node_sh *nodesh)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = nodesh->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		changed_to_home(nodesh);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		changed_previous(nodesh);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		changed_dot(nodesh);
		return (1);
	}

	changed_to(nodesh);

	return (1);
}
