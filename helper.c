#include "main.h"

/**
 * environ_helper - This helper prints information for env
 */
void environ_helper(void)
{
	char *env_help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STRDOUT_FILENO, env_help, _strlen(env_help));
	env_help = "Print the environment of the shell.\n";
	write(STDOUT_FILENO, env_help, _strlen(env_help));
}

/**
 * setenv_helper - this helper prints info for setenv
 */
void setenv_helper(void)
{
	char *setenv_help = "setenv: setenv (const char *name, ";

	write(STDOUT_FILENO, setenv_help, _strlen(setenv_help));
	setenv_help = "const char *value, int replace)\n\t";
	write(STDOUT_FILENO, setenv_help, _strlen(setenv_help));
	setenv_help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, setenv_help, _strlen(setenv_help));
}

/**
 * unsetenv_helper - this helper printss info for unsetenv
 */
void unsetenv_helper(void)
{
	char *unset_help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, unset_help, _strlen(unset_help));
	unset_help = "Erase an entire entry from the environment\n";
	write(STDOUT_FILENO, unset_help, _strlen(unset_help));
}

/**
 * general_info - this helper prints the general help info
 */
void general_info(void)
{
	char *geninfo = "JOHANNE bash, version 1.0.0(1)-release\n";

	write(STDOUT_FILENO, geninfo, _strlen(geninfo));
	geninfo = "These shell commands are defined internally. Type 'help'";
	write(STDOUT_FILENO, geninfo, _strlen(geninfo));
	geninfo = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, geninfo, _strlen(geninfo));
}

/**
 * exit_helper - this help prints info about exit
 */
void exit_helper(void)
{
	char *exit_help = "exit: exit [n]\n Quit shell.\n";

	write(STDOUT_FILENO, exit_help, _strlen(exit_help));
	exit_help = "Quits the shell with a status";
	write(STDOUTFILENO, exit_help, _strlen(exit_help));
}
