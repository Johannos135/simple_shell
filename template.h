#ifndef _TEMPLATE_
#define _TEMPLATE_

#define TAILLEBUF 1024
#define TOK_TAILLEBUF 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct donnee - structure de donne
 * @argv: argument vector
 * @entree: valeur d'entrer
 * @args: jzton
 * @status: last status
 * @counter: ldanses counter
 * @_environ: variable d'environ
 * @pid: ID du processus
 */
typedef struct donnee
{
	char **argv;
	char *entree;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} node_sh;

/**
 * struct div_list_s - struct diviseur
 * @separator: ; | &
 * @next: noeud suivant
 */
typedef struct div_list_s
{
	char separator;
	struct div_list_s *next;
} div_list;

/**
 * struct ligne_s - tructure ligne
 * @ldanse: ligne de commande
 * @next: noeud suivant
 */
typedef struct ligne_s
{
	char *ldanse;
	struct ligne_s *next;
} ligne;

/**
 * struct store_var_list - structure var
 * @longu_var: longuueur variable
 * @val: valeur
 * @longu_val: longuueur valeur
 * @next: noeud suivant
 */
typedef struct store_var_list
{
	int longu_var;
	char *val;
	int longu_val;
	struct store_var_list *next;
} store_var;

/**
 * struct builtdans_s - structure commande preconstruite
 * @nom: nom des commandes
 * @f: donnee function
 */
typedef struct builtdans_s
{
	char *nom;
	int (*f)(node_sh *nodesh);
} builtdans_t;

#endif
