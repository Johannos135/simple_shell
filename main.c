#include "main.h"

/**
 * dt_fr - makes data free after use
 * @nodesh: node value
 */
void dt_fr(node_sh *nodesh)
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
 * data_setter - set data
 * @nodesh: data structure
 * @argv: argument vector
 */
void data_setter(node_sh *nodesh, char **argv)
{
	unsigned int count = 0;

	nodesh->argv = argv;
	nodesh->input = NULL;
	nodesh->args = NULL;
	nodesh->status = 0;
	nodesh->cpt = 1;

	while (environ[count])
		count++;

	nodesh->_environ = malloc(sizeof(char *) * (count + 1));

	while (environ[count])
	{
		nodesh->_environ[count] = _strdup(environ[count]);
		count++;
	}

	nodesh->_environ[count] = NULL;
	nodesh->pid = cus_itoa(getpid());
}

/**
 * main - Entry point
 * @argc: argument vector counter
 * @argv: argument vector
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	node_sh nodesh;
	(void) argc;

	signal(SIGINT, _sigint_g);
	data_setter(&nodesh, argv);
	runner(&nodesh);
	dt_fr(&nodesh);
	if (nodesh.status < 0)
		return (255);
	return (nodesh.status);
}
