#include "main.h"

/**
 * helper1_env - Aide sur les variables d'environnemment
 */
void helper1_env(void)
{
	char *help = "env: env [option] [nom=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlongu(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, _strlongu(help));

}
/**
 * helper1_setenv - Aide sur le buitdans setenv
 */
void helper1_setenv(void)
{

	char *help = "setenv: setenv (const char *nom, const char *value,";

	write(STDOUT_FILENO, help, _strlongu(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, _strlongu(help));
	help = "Add a new defdansition to the environment\n";
	write(STDOUT_FILENO, help, _strlongu(help));
}
/**
 * helper1_unsetenv - Aide sur le builtdans unset env
 */
void helper1_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *nom)\n\t";

	write(STDOUT_FILENO, help, _strlongu(help));
	help = "Rebougee an entry completely from the environment\n";
	write(STDOUT_FILENO, help, _strlongu(help));
}


/**
 * helper1_general - Information general
 */
void helper1_general(void)
{
	char *help = "Johanne bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlongu(help));
	help = "These commands are defdansed internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, _strlongu(help));
	help = "Type 'help nom' to fdansd out more about the function 'nom'.\n\n ";
	write(STDOUT_FILENO, help, _strlongu(help));
	help = " alias: alias [nom=['strdansg']]\n changed: changed [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _strlongu(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [nom=value] [command ";
	write(STDOUT_FILENO, help, _strlongu(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _strlongu(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlongu(help));
}
/**
 * helper1_exit - Information sur la builtdans quitter
 */
void helper1_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlongu(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, _strlongu(help));
	help = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, help, _strlongu(help));
}
