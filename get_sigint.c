#include "main.h"

/**
 * signal_getter - gere la combinaison ctrl + c
 * @sig: gestion du signal
 */
void signal_getter(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
