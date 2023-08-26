#include "main.h"

/**
 * changed_dot - redirige vers le dossier parent
 * @nodesh: structure de la donnée
 */
void changed_dot(node_sh *nodesh)
{
	char pwd[PATH_MAX];
	char *dir, *copypwd, *copystrtok_pwd;

	getcwd(pwd, sizeof(pwd));
	copypwd = _strdup(pwd);
	set_env("OLDPWD", copypwd, nodesh);
	dir = nodesh->args[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("PWD", copypwd, nodesh);
		free(copypwd);
		return;
	}
	if (_strcmp("/", copypwd) == 0)
	{
		free(copypwd);
		return;
	}
	copystrtok_pwd = copypwd;
	reverse_str(copystrtok_pwd);
	copystrtok_pwd = _strtok(copystrtok_pwd, "/");
	if (copystrtok_pwd != NULL)
	{
		copystrtok_pwd = _strtok(NULL, "\0");

		if (copystrtok_pwd != NULL)
			reverse_str(copystrtok_pwd);
	}
	if (copystrtok_pwd != NULL)
	{
		chdir(copystrtok_pwd);
		set_env("PWD", copystrtok_pwd, nodesh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", nodesh);
	}
	nodesh->status = 0;
	free(copypwd);
}

/**
 * changed_to - redirige vers un repertoire donne
 * @nodesh: structure de la donnee
 */
void changed_to(node_sh *nodesh)
{
	char pwd[PATH_MAX];
	char *dir, *copypwd, *copydir;

	getcwd(pwd, sizeof(pwd));

	dir = nodesh->args[1];
	if (chdir(dir) == -1)
	{
		get_err(nodesh, 2);
		return;
	}

	copypwd = _strdup(pwd);
	set_env("OLDPWD", copypwd, nodesh);

	copydir = _strdup(dir);
	set_env("PWD", copydir, nodesh);

	free(copypwd);
	free(copydir);

	nodesh->status = 0;

	chdir(dir);
}

/**
 * changed_previous - dirige vers le rep precedent
 * @nodesh: structure de la donnee
 */
void changed_previous(node_sh *nodesh)
{
	char pwd[PATH_MAX];
	char *print_pwd, *p_oldpwd, *copypwd, *copyoldpwd;

	getcwd(pwd, sizeof(pwd));
	copypwd = _strdup(pwd);

	p_oldpwd = _getenv("OLDPWD", nodesh->_environ);

	if (p_oldpwd == NULL)
		copyoldpwd = copypwd;
	else
		copyoldpwd = _strdup(p_oldpwd);

	set_env("OLDPWD", copypwd, nodesh);

	if (chdir(copyoldpwd) == -1)
		set_env("PWD", copypwd, nodesh);
	else
		set_env("PWD", copyoldpwd, nodesh);

	print_pwd = _getenv("PWD", nodesh->_environ);

	write(STDOUT_FILENO, print_pwd, _strlongu(print_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(copypwd);
	if (p_oldpwd)
		free(copyoldpwd);

	nodesh->status = 0;

	chdir(print_pwd);
}

/**
 * changed_to_home - retour à l'accueil
 * @nodesh: donnee de la structure
 */
void changed_to_home(node_sh *nodesh)
{
	char *print_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	print_pwd = _strdup(pwd);

	home = _getenv("HOME", nodesh->_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", print_pwd, nodesh);
		free(print_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_err(nodesh, 2);
		free(print_pwd);
		return;
	}

	set_env("OLDPWD", print_pwd, nodesh);
	set_env("PWD", home, nodesh);
	free(print_pwd);
	nodesh->status = 0;
}
