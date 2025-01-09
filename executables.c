#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 *exec_command- Parse a command and if valid, executes it
 *@command: input given as a command to exec
 *@program_name: Name of the program
 *Return: Nothing void
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
			{
				perror("fork :");
				return;
			}
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
	free_array(tokens);
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
	ssize_t read_bytes;

	while (1)
	{
		printf("#cisfun$ ");
		read_bytes = getline(&command, &len, stdin);
		if (read_bytes > 0)
		{
			remove_newline(command);
			if (_strspn(command, " ") == strlen(command))
			continue;
			if (strcmp(command, "exit") == 0)
				break;
			exec_command(command, program_name);
		}
		else if (read_bytes == 0)
		continue;
		else if (read_bytes < 0)
		{
			perror("Exiting shell...");
			break;
		}
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
	ssize_t read_bytes;

	read_bytes = getline(&command, &len, stdin);
	while (read_bytes != -1)
	{
		remove_newline(command);
		if ((strlen(command) == 0) || (_strspn(command, " ") == strlen(command)))
		{
			printf("\n");
			exit(0);
		}
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

/**
	 *find_executable- search for a file in the PATH
	 *@str: File to search for
	 *Return: Absolute path of the file
	 */
	char *find_executable(char *str)
	{
		char *path;
		char *path_copy;
		char *directory;
		char *final_path;

		path = _getenv("PATH");
		if (path == NULL)
			return (NULL);
		path_copy = strdup(path);
		if (path_copy == NULL)
			return (NULL);
		directory = strtok(path_copy, ":");
		while (directory != NULL)
		{
			final_path = malloc((strlen(directory) + (strlen(str)) + 2) * sizeof(char));
			if (final_path == NULL)
			{
				free(path_copy);
				return (NULL);
			}
			sprintf(final_path, "%s/%s", directory, str);
			if (access(final_path, X_OK) == 0)
			{
				free(path_copy);
				return (final_path);
			}
			free(final_path);
			directory = strtok(NULL, ":");
		}
		free(path_copy);
		return (NULL);
	}
