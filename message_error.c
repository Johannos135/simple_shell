#include "main.h"

/**
 * concat_error - this function aims to concatanate the error msg
 * @nodesh: this parameter targets the directory
 * @message: return the error message
 * @bad: this aims to print the message
 * @counter: this count the number of lines.
 *
 * Return: full error message.
 */
char *concat_error(node_sh *nodesh, char *message, char *bad,
		char *counter)
{
	char *drapeau;

	_strcpy(bad, nodesh->argv[0]);
	_strcat(bad, ": ");
	_strcat(bad, counter);
	_strcat(bad, ": ");
	_strcat(bad, nodesh->args[0]);
	_strcat(bad, message);

	if (nodesh->args[1][0] == '-')
	{
		drapeau = malloc(3);
		drapeau[0] = '-';
		drapeau[1] = nodesh->args[1][1];
		drapeau[2] = '\0';

		_strcat(bad, drapeau);
		free(drapeau);
	}
	else
	{
		_strcat(bad, nodesh->args[1]);
	}
	_strcat(bad, "\n");
	_strcat(bad, "\0");
	return (bad);
}

/**
 * directory_err - Retrieve the error message for cd command
 * @nodesh: this target the directory
 *
 * Return: the corresponding error message.
 */
char *directory_err(node_sh *nodesh)
{
	int longueur, ident;
	char *message_er, *counter, *message;

	counter = _itoa(nodesh->cpt);

	if (nodesh->args[1][0] == '-')
	{
		message = ": This is not valid ";
		ident = 2;
	}
	else
	{
		message = ": no file or Directory to ";
		ident = _strlen(nodesh->args[1]);
	}

	longueur = _strlen(nodesh->argv[0]) + _strlen(nodesh->args[0]);
	longueur += _strlen(counter) + _strlen(message) + ident + 5;
	message_er = malloc(sizeof(char) * (longueur + 1));

	if (message_er == 0)
	{
		free(counter);
		return (NULL);
	}
	message_er = concat_error(nodesh, message, message_er, counter);

	free(counter);

	return (message_er);
}
