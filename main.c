#include "main.h"

/**
 * free_donnee - frees donnee structure
 *
 * @nodesh: donnee structure
 * Return: no return
 */
void free_donnee(node_sh *nodesh)
{
	unsigned int i;

	for (i = 0; nodesh->_environ[i]; i++)
	{
		free(nodesh->_environ[i]);
	}

	free(nodesh->_environ);
	free(nodesh->pid);
}

/**
 * set_donnee - Initialize donnee structure
 *
 * @nodesh: donnee structure
 * @argv: argument vector
 */
void set_donnee(node_sh *nodesh, char **argv)
{
	unsigned int i;

	nodesh->argv = argv;
	nodesh->entree = NULL;
	nodesh->args = NULL;
	nodesh->status = 0;
	nodesh->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	nodesh->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		nodesh->_environ[i] = _strdup(environ[i]);
	}

	nodesh->_environ[i] = NULL;
	nodesh->pid = helper_itoa(getpid());
}

/**
 * main - Point de départ
 * @argc: argument vector count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	node_sh nodesh;
	(void) argc;

	signal(SIGINT, signal_getter);
	set_donnee(&nodesh, argv);
	shell_boucle(&nodesh);
	free_donnee(&nodesh);
	if (nodesh.status < 0)
		return (255);
	return (nodesh.status);
}
