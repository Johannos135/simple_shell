#include "main.h"

/*
 * prompt - prompts the user for and input
 * and writes $ after running a program
 */

void prompt(void)
{
	write(STDIN_FILENO,"$",2);
}
