#include "main.h"

/**
 * repeated_char - compte le nombre de charactere
 * @entree: entree chaine
 * @i: indice
 * Return: chaine repetitive
 */
int repeated_char(char *entree, int i)
{
	if (*(entree - 1) == *entree)
		return (repeated_char(entree - 1, i + 1));

	return (i);
}

/**
 * err_sep_op - valeur d'erreur
 * @entree: entree chaine
 * @i: indice
 * @last: dernier char à lire
 * Return: indice erreur
 */
int err_sep_op(char *entree, int i, char last)
{
	int count;

	count = 0;
	if (*entree == '\0')
		return (0);

	if (*entree == ' ' || *entree == '\t')
		return (err_sep_op(entree + 1, i + 1, last));

	if (*entree == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*entree == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = repeated_char(entree, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*entree == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = repeated_char(entree, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (err_sep_op(entree + 1, i + 1, *entree));
}

/**
 * first_char - trouve le premier char
 * @entree: entree strdansg
 * @i: indice
 * Return: 1 si erreur.
 */
int first_char(char *entree, int *i)
{

	for (*i = 0; entree[*i]; *i += 1)
	{
		if (entree[*i] == ' ' || entree[*i] == '\t')
			continue;

		if (entree[*i] == ';' || entree[*i] == '|' || entree[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_err - affiche quand a syntax err is found
 * @nodesh: donnee structure
 * @entree: entree strdansg
 * @i: dansdex of the err
 * @checker: to control message err
 */
void print_syntax_err(node_sh *nodesh, char *entree, int i, int checker)
{
	char *message, *message2, *message3, *err, *counter;
	int longugth;

	if (entree[i] == ';')
	{
		if (checker == 0)
			message = (entree[i + 1] == ';' ? ";;" : ";");
		else
			message = (entree[i - 1] == ';' ? ";;" : ";");
	}

	if (entree[i] == '|')
		message = (entree[i + 1] == '|' ? "||" : "|");

	if (entree[i] == '&')
		message = (entree[i + 1] == '&' ? "&&" : "&");

	message2 = ": Syntax err: \"";
	message3 = "\" unexpected\n";
	counter = helper_itoa(nodesh->counter);
	longugth = _strlongu(nodesh->argv[0]) + _strlongu(counter);
	longugth += _strlongu(message) + _strlongu(message2) + _strlongu(message3) + 2;

	err = malloc(sizeof(char) * (longugth + 1));
	if (err == 0)
	{
		free(counter);
		return;
	}
	_strcpy(err, nodesh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, counter);
	_strcat(err, message2);
	_strcat(err, message);
	_strcat(err, message3);
	_strcat(err, "\0");

	write(STDERR_FILENO, err, longugth);
	free(err);
	free(counter);
}

/**
 * check_syntax_err - syntaxe à verifier
 * @nodesh: donnee structure
 * @entree: entree chaine
 * Return: 1 si erreur
 */
int check_syntax_err(node_sh *nodesh, char *entree)
{
	int begdans = 0;
	int valeur_f = 0;
	int i = 0;

	valeur_f = first_char(entree, &begdans);
	if (valeur_f == -1)
	{
		print_syntax_err(nodesh, entree, begdans, 0);
		return (1);
	}

	i = err_sep_op(entree + begdans, 0, *(entree + begdans));
	if (i != 0)
	{
		print_syntax_err(nodesh, entree, begdans + i, 1);
		return (1);
	}

	return (0);
}
