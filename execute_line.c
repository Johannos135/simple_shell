#include "main.h"

/**
 * exec_ldanse - fdansds builtdanss and commands
 *
 * @nodesh: donnee relevant (args)
 * Return: 1 on success.
 */
int exec_ldanse(node_sh *nodesh)
{
	int (*builtdans)(node_sh *nodesh);

	if (nodesh->args[0] == NULL)
		return (1);

	builtdans = get_builtdans(nodesh->args[0]);

	if (builtdans != NULL)
		return (builtdans(nodesh));

	return (execute_cmd(nodesh));
}
