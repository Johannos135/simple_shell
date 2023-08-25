#include "main.h"

/**
 * cpt_char - this function counts the number of
 * times a char is used
 * @value: entry value
 * @count: this represents the index
 *
 * Return: the number of times
 */
int cpt_char(char *value, int count)
{
	if (*(value - 1) == *value)
		return (cpt_char(value - 1, count + 1));

	return (count);
}

/**
 * error_dividor - locates error
 * @value: parameter of the value
 * @count:counter
 * @dernier: last character read
 *
 * Return: error positioning
 */
int error_dividor(char *value, int count, char dernier)
{
	int counter = 0;

	if (*value == '\0')
		return (0);

	if (*value == ' ' || *value == '\t')
		return (error_dividor(value + 1, count + 1, dernier));

	if (*value == ';')
		if (dernier == '|' || dernier == '&' || dernier == ';')
			return (count);

	if (*value == '|')
	{
		if (dernier == ';' || dernier == '&')
			return (count);

		if (dernier == '|')
		{
			counter = cpt_char(value, 0);
			if (counter == 0 || counter > 1)
				return (count);
		}
	}

	if (*value == '&')
	{
		if (dernier == ';' || dernier == '|')
			return (count);

		if (dernier == '&')
		{
			counter = cpt_char(value, 0);
			if (counter == 0 || counter > 1)
				return (count);
		}
	}

	return (error_dividor(value + 1, count + 1, *value));
}

/**
 * char_indice - locates char index
 * @value: value value
 * @count: index of the char
 * Return: two possible value 1 or 0
 */
int char_indice(char *value, int *count)
{

	for (*count = 0; value[*count]; *count += 1)
	{
		if (value[*count] == ' ' || value[*count] == '\t')
			continue;

		if (value[*count] == ';' || value[*count] == '|' || value[*count] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * display_error_syntax - prints when a syntax error is found
 *
 * @nodesh: node data and value
 * @value: value string
 * @i: represents error index
 * @check: checks  message error
 */
void display_error_syntax(node_sh *nodesh, char *value, int i, int check)
{
	char *message, *message2, *message3, *error, *counter;
	int length;

	if (value[i] == ';')
	{
		if (check == 0)
			message = (value[i + 1] == ';' ? ";;" : ";");
		else
			message = (value[i - 1] == ';' ? ";;" : ";");
	}

	if (value[i] == '|')
		message = (value[i + 1] == '|' ? "||" : "|");

	if (value[i] == '&')
		message = (value[i + 1] == '&' ? "&&" : "&");

	message2 = ": Syntax error: \"";
	message3 = "\" unexpected\n";
	counter = cus_itoa(nodesh->cpt);
	length = _strlen(nodesh->argv[0]) + _strlen(counter);
	length += _strlen(message) + _strlen(message2) + _strlen(message3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, nodesh->argv[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, message2);
	_strcat(error, message);
	_strcat(error, message3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * syntax_verify - verify intermediate function to display
 *
 * @nodesh: node data and value
 * @value: value string
 * Return: 1 if error or 0
 */
int syntax_verify(node_sh *nodesh, char *value)
{
	int start = 0;
	int first_index_c = 0;
	int i = 0;

	first_index_c = char_indice(value, &start);
	if (first_index_c == -1)
	{
		display_error_syntax(nodesh, value, start, 0);
		return (1);
	}

	i = error_dividor(value + start, 0, *(value + start));
	if (i != 0)
	{
		display_error_syntax(nodesh, value, start + i, 1);
		return (1);
	}

	return (0);
}
