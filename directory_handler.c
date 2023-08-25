#include "main.h"

/**
 * changed_dot - changes directory one level up
 * @nodesh: node value
 */
void changed_dot(node_sh *nodesh)
{
	char print_wd[PATH_MAX];
	char *directory, *copy_pwd, *_tokenize;

	getcwd(print_wd, sizeof(print_wd));
	copy_pwd = _strdup(print_wd);
	set_env("OLDPWD", copy_pwd, nodesh);
	directory = nodesh->args[1];
	if (_strcmp(".", directory) == 0)
	{
		set_env("PWD", copy_pwd, nodesh);
		free(copy_pwd);
		return;
	}
	if (_strcmp("/", copy_pwd) == 0)
	{
		free(copy_pwd);
		return;
	}
	_tokenize = copy_pwd;
	reverse_str(_tokenize);
	_tokenize = _strtok(_tokenize, "/");
	if (_tokenize != NULL)
	{
		_tokenize = _strtok(NULL, "\0");

		if (_tokenize != NULL)
			reverse_str(_tokenize);
	}
	if (_tokenize != NULL)
	{
		chdir(_tokenize);
		set_env("PWD", _tokenize, nodesh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", nodesh);
	}
	nodesh->status = 0;
	free(copy_pwd);
}

/**
 * changed_to - this function aims to shift to another dir
 * @nodesh: node value
 */
void changed_to(node_sh *nodesh)
{
	char print_wd[PATH_MAX];
	char *directory, *copy_pwd, *copy_dir;

	getcwd(print_wd, sizeof(print_wd));

	directory = nodesh->args[1];
	if (chdir(directory) == -1)
	{
		_error_g(nodesh, 2);
		return;
	}

	copy_pwd = _strdup(print_wd);
	set_env("OLDPWD", copy_pwd, nodesh);

	copy_dir = _strdup(directory);
	set_env("PWD", copy_dir, nodesh);

	free(copy_pwd);
	free(copy_dir);

	nodesh->status = 0;

	chdir(directory);
}

/**
 * changed_previous - this function allows to return to
 * the previous directory
 * @nodesh: node value.
 */
void changed_previous(node_sh *nodesh)
{
	char print_wd[PATH_MAX];
	char *point_pwd, *point_old, *copy_pwd, *copy_old;

	getcwd(print_wd, sizeof(print_wd));
	copy_pwd = _strdup(print_wd);

	point_old = _getenv("OLDPWD", nodesh->_environ);

	if (point_old == NULL)
		copy_old = copy_pwd;
	else
		copy_old = _strdup(point_old);

	set_env("OLDPWD", copy_pwd, nodesh);

	if (chdir(copy_old) == -1)
		set_env("PWD", copy_pwd, nodesh);
	else
		set_env("PWD", copy_old, nodesh);

	point_pwd = _getenv("PWD", nodesh->_environ);

	write(STDOUT_FILENO, point_pwd, _strlen(point_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(copy_pwd);
	if (point_old)
		free(copy_old);

	nodesh->status = 0;

	chdir(point_pwd);
}

/**
 * changed_to_home - changes to home directory
 * @nodesh: node value
 */
void changed_to_home(node_sh *nodesh)
{
	char *point_pwd, *accueil;
	char print_wd[PATH_MAX];

	getcwd(print_wd, sizeof(print_wd));
	point_pwd = _strdup(print_wd);

	accueil = _getenv("HOME", nodesh->_environ);

	if (accueil == NULL)
	{
		set_env("OLDPWD", point_pwd, nodesh);
		free(point_pwd);
		return;
	}

	if (chdir(accueil) == -1)
	{
		_error_g(nodesh, 2);
		free(point_pwd);
		return;
	}

	set_env("OLDPWD", point_pwd, nodesh);
	set_env("PWD", accueil, nodesh);
	free(point_pwd);
	nodesh->status = 0;
}
