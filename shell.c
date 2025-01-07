#include "main.h"

/**
 * main - the simple shell project
 *
 * Return: Always 0
 */

int main(void)
{
	char *command = NULL;
	char **tokens = NULL;
	size_t len = 0;
	int a = 0;
	int i;

	while (1)
	{
		printf("$ ");
		if (getline(&command, &len, stdin) > 0)
		{
			remove_newline(command);
			if (strcmp(command, "exit") == 0)
				break;
			tokens = split_string(command);
			while (tokens[a])
			{
				printf("%s\n", tokens[a]);
				a++;
			}
			a = 0;
			comm_exec(tokens);
			for (i = 0; tokens[i] != NULL; i++)
				free(tokens[i]);
			free(tokens);
		}
		else if (getline(&command, &len, stdin) == -1)
		{
			printf("\n");
			break;
		}
	}
	free(command);
	return (0);
}
