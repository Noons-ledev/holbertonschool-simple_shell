#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
*main- Entry of program
*@argc: Argument count
*@argv: array of arguments
*Return: Always 0 (Success)
*/

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (isatty(STDIN_FILENO))
	exec_loop(argv[0]);
	else
	exec_no_loop(argv[0]);
	return (0);
}
