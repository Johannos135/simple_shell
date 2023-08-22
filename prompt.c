#include "main.h"

/**
 * prompt - prompts the user for and input
 * and writes $ after running a program
 *
 * Description: this function uses write function
 * to display the prompt
 */

void prompt(void)
{
	write(STDIN_FILENO, "$ ", 2);
}
