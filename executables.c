#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 *exec_command- Parse a command and if valid, executes it
 *@command: input given as a command to exec
 *@program_name: Name of the program
 */
void exec_command(char *command, char *program_name)
{
	char **tokens;
	int id, status;
	char *absolute_path;

	tokens = split_string(command);
	if (tokens == NULL)
		return;
	if (tokens[0][0] == '/' || tokens[0][0] == '.')
		absolute_path = strdup(tokens[0]);
	else
		{
		absolute_path = find_executable(tokens[0]);
		}	
	if (absolute_path)
	{
		if (access(absolute_path, X_OK) == 0)
		{
			id = fork();
			if (id == -1)
				return;
			else if (id != 0)
				wait(&status);
			else if (id == 0)
				execve(absolute_path, tokens, NULL);
		}
		else
			printf("%s: No such file or directory\n", program_name);
	}
	else if (!absolute_path)
		printf("%s: Command not found\n", program_name);
	free(absolute_path);
	free(tokens);
}
/**
 *exec_loop- Infinite loop that process to execute user inputs
 *@program_name: Name of the shell
 *Return: 0 for success
 */
int exec_loop(char *program_name)
{
	char *command = NULL;
	size_t len = 0;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&command, &len, stdin) > 0)
		{
			remove_newline(command);
			if (strcmp(command, "exit") == 0)
				break;
			exec_command(command, program_name);
		}
		else
			break;
	}
	free(command);
	return (0);
}
/**
 *exec_no_loop- Enter non interactive mode
 *@program_name: Name of program passed as arg for error messages
 *Return: 0 for success
 */
int exec_no_loop(char *program_name)
{
	char *command = NULL;
	size_t len = 0;

	if (getline(&command, &len, stdin) > 0)
	{
		remove_newline(command);
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			exit(0);
		}
		exec_command(command, program_name);
	}
	free(command);
	return (0);
}
