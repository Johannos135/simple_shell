#include "main.h"

/**
 * is_cdir - veriy if ":"  is in the current directory.
 * @chemin: path towards char.
 * @count: index ptr
 * Return: 1 or  0 otherwise.
 */
int is_cdir(char *chemin, int *count)
{
	if (chemin[*count] == ':')
		return (1);

	while (chemin[*count] != ':' && chemin[*count])
	{
		*count += 1;
	}

	if (chemin[*count])
		*count += 1;

	return (0);
}

/**
 * _which - gives command position
 * @cmd: command name
 * @_environ: variable d'environment
 * Return: command position.
 */
char *_which(char *cmd, char **_environ)
{
	char *chemin, *ptr_chemin, *token_chemin, *dir;
	int sizeof_direct, sizeof_cmd, i;
	struct stat st;

	chemin = _getenv("PATH", _environ);
	if (chemin)
	{
		ptr_chemin = _strdup(chemin);
		sizeof_cmd = _strlen(cmd);
		token_chemin = _strtok(ptr_chemin, ":");
		i = 0;
		while (token_chemin != NULL)
		{
			if (is_cdir(chemin, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			sizeof_direct = _strlen(token_chemin);
			dir = malloc(sizeof_direct + sizeof_cmd + 2);
			_strcpy(dir, token_chemin);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_chemin);
				return (dir);
			}
			free(dir);
			token_chemin = _strtok(NULL, ":");
		}
		free(ptr_chemin);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - guesses if exec
 * @nodesh: node value
 * Return: 0(Success)
 */
int is_executable(node_sh *nodesh)
{
	struct stat st;
	int i;
	char *countnput;

	countnput = nodesh->args[0];
	for (i = 0; countnput[i]; i++)
	{
		if (countnput[i] == '.')
		{
			if (countnput[i + 1] == '.')
				return (0);
			if (countnput[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (countnput[i] == '/' && i != 0)
		{
			if (countnput[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(countnput + i, &st) == 0)
	{
		return (i);
	}
	_error_g(nodesh, 127);
	return (-1);
}

/**
 * cmd_code_checker - verifies if users got permissions or not
 *
 * @dir: target directory
 * @nodesh: node value
 * Return: 1 or 0 if no error
 */
int cmd_code_checker(char *dir, node_sh *nodesh)
{
	if (dir == NULL)
	{
		_error_g(nodesh, 127);
		return (1);
	}

	if (_strcmp(nodesh->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			_error_g(nodesh, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(nodesh->args[0], X_OK) == -1)
		{
			_error_g(nodesh, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * execute_cmd - this function executes command lines
 * @nodesh: node value
 * Return: if true 1
 */
int execute_cmd(node_sh *nodesh)
{
	pid_t pd;
	pid_t work_pd;
	int etat;
	int exec;
	char *dir;
	(void) work_pd;

	exec = is_executable(nodesh);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(nodesh->args[0], nodesh->_environ);
		if (cmd_code_checker(dir, nodesh) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(nodesh->args[0], nodesh->_environ);
		else
			dir = nodesh->args[0];
		execve(dir + exec, nodesh->args, nodesh->_environ);
	}
	else if (pd < 0)
	{
		perror(nodesh->argv[0]);
		return (1);
	}
	else
	{
		do {
			work_pd = waitpid(pd, &etat, WUNTRACED);
		} while (!WIFEXITED(etat) && !WIFSIGNALED(etat));
	}

	nodesh->status = etat / 256;
	return (1);
}
