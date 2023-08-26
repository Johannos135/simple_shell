#include "main.h"

/**
 * get_builtdans - recupere la variable preconstruite
 * @cmd: commande à retourner
 * Return: variable preconstruite
 */
int (*get_builtdans(char *cmd))(node_sh *)
{
	builtdans_t builtdans[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "changed", changed_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtdans[i].nom; i++)
	{
		if (_strcmp(builtdans[i].nom, cmd) == 0)
			break;
	}

	return (builtdans[i].f);
}
