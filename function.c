#include "main.h"

/**
 * remove_newline - remove the '\n'
 *
 * @str: the string
 */

void remove_newline(char *str)
{
	size_t len = strlen(str);

	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

/**
 * comm_exec - execute the command from the user
 *
 * @command: the command
 *
 * Return: 0 if success or -1 if it's fail
 */

int comm_exec(char **command)
{
	pid_t pid;
	int status;
	char *env[] = {NULL};
	char *full_path;

	full_path = find_command_path(command[0]);
	if (full_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", command[0]);
		return (-1);
	}

	pid = fork();
	if (pid < 0)
	{
		fprintf(stderr, "Fork failed for process\n");
		free(full_path);
		exit(1);
	}
	else if (pid == 0)
	{
		execve(full_path, command, env);
		perror("execve");
		free(full_path);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			printf("Child process %d completed with exit status %d\n"
					, pid, WEXITSTATUS(status));
		free(full_path);
	}
	return (0);
}
