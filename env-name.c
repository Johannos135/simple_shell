#include "main.h"

/**
 * cmp_env_nom - compare le nom de la var d'env
 * @nom_env: nom de la var d'env
 * @nom: nom passe en param
 * Return: 0 si egal
 */
int cmp_env_nom(const char *nom_env, const char *nom)
{
	int i;

	for (i = 0; nom_env[i] != '='; i++)
	{
		if (nom_env[i] != nom[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - recup la var d'en
 * @nom: nom de la var d'env
 * @_environ: variable d'environnement
 * Return: retourne la var d'env
 */
char *_getenv(const char *nom, char **_environ)
{
	char *pterenv;
	int i, bouge;

	pterenv = NULL;
	bouge = 0;

	for (i = 0; _environ[i]; i++)
	{
		bouge = cmp_env_nom(_environ[i], nom);
		if (bouge)
		{
			pterenv = _environ[i];
			break;
		}
	}

	return (pterenv + bouge);
}

/**
 * _env - affiche la var d'env
 * @nodesh: structure de la donnee.
 * Return: 1 si vrai.
 */
int _env(node_sh *nodesh)
{
	int i, j;

	for (i = 0; nodesh->_environ[i]; i++)
	{

		for (j = 0; nodesh->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, nodesh->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	nodesh->status = 0;

	return (1);
}
