#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 *main-entry of program
 * @argc: arg count
 * @argv: array of pointer to args
 * Return: Always 0 for success
 */
int main(int argc, char **argv)
{
	(void)argc;
	if (isatty(STDIN_FILENO))
		exec_loop(argv[0]);
	else
		exec_no_loop(argv[0]);
	return (0);
}
