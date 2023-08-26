#include "main.h"

/**
 * is_changedir - checks ":" if is dans the current directory.
 * @path: type char pointer char.
 * @i: type int pointer of dansdex.
 * Return: 1 if the path is searchable dans the changed, 0 otherwise.
 */
int is_changedir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _which - locates a command
 *
 * @cmd: command nom
 * @_environ: environment variable
 * Return: location of the command.
 */
char *_which(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int longu_dir, longu_cmd, i;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		longu_cmd = _strlongu(cmd);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_changedir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			longu_dir = _strlongu(token_path);
			dir = malloc(longu_dir + longu_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
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
 * is_executable - determdanses if is an executable
 *
 * @nodesh: donnee structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_executable(node_sh *nodesh)
{
	struct stat st;
	int i;
	char *entree;

	entree = nodesh->args[0];
	for (i = 0; entree[i]; i++)
	{
		if (entree[i] == '.')
		{
			if (entree[i + 1] == '.')
				return (0);
			if (entree[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (entree[i] == '/' && i != 0)
		{
			if (entree[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(entree + i, &st) == 0)
	{
		return (i);
	}
	get_err(nodesh, 127);
	return (-1);
}

/**
 * check_err_cmd - verifies if user has permissions to access
 *
 * @dir: destdansation directory
 * @nodesh: donnee structure
 * Return: 1 if there is an err, 0 if not
 */
int check_err_cmd(char *dir, node_sh *nodesh)
{
	if (dir == NULL)
	{
		get_err(nodesh, 127);
		return (1);
	}

	if (_strcmp(nodesh->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_err(nodesh, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(nodesh->args[0], X_OK) == -1)
		{
			get_err(nodesh, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * execute_cmd - executes command ldanses
 *
 * @nodesh: donnee relevant (args and entree)
 * Return: 1 on success.
 */
int execute_cmd(node_sh *nodesh)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(nodesh);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(nodesh->args[0], nodesh->_environ);
		if (check_err_cmd(dir, nodesh) == 1)
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
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	nodesh->status = state / 256;
	return (1);
}
