#include "main.h"

/**
 * helper1 - aide sur aide
 */
void helper1(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlongu(help));
	help = "\tDisplay dansformation about builtdans commands.\n ";
	write(STDOUT_FILENO, help, _strlongu(help));
	help = "Displays brief summaries of builtdans commands.\n";
	write(STDOUT_FILENO, help, _strlongu(help));
}
/**
 * helper1_alias - aide sur alias
 */
void helper1_alias(void)
{
	char *help = "alias: alias [-p] [nom[=value]...]\n";

	write(STDOUT_FILENO, help, _strlongu(help));
	help = "\tDefdanse or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlongu(help));
}
/**
 * helper1_changed - aide sur changed
 */
void helper1_changed(void)
{
	char *help = "changed: changed [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlongu(help));
	help = "\tChange the shell workdansg directory.\n ";
	write(STDOUT_FILENO, help, _strlongu(help));
}
