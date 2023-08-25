#include "main.h"

/**
 * path_err - this function aims to print errors related to path
 * @nodesh: data to be entered as parameter
 *
 * Return: path error message
 */
char *path_err(node_sh *nodesh)
{
	int size_er;
	char *message_er, *counter;

	counter = cus_itoa(nodesh->cpt);
	size_er = _strlen(nodesh->argv[0]) + _strlen(counter);
	size_er += _strlen(nodesh->args[0]) + 24;
	message_er = malloc(sizeof(char) * (size_er + 1));

	if (message_er == 0)
	{
		free(message_er);
		free(counter);
		return (NULL);
	}
	_strcpy(message_er, nodesh->argv[0]);
	_strcat(message_er, ": ");
	_strcat(message_er, counter);
	_strcat(message_er, ": ");
	_strcat(message_er, nodesh->args[0]);
	_strcat(message_er, ": Permission denied\n");
	_strcat(message_er, "\0");
	free(counter);
	return (message_er);
}
