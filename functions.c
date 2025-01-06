#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
*split_string- Splits a string in elements of an array
*@str: String to split
*Return: array of pointers (pointer to pointer)
*/
char **split_string(char *str)
{
char **tokens_array;
char *token;
int i = 0, j = 0, words_number = 0;
	for (; str[j]; j++)
	{
		if (str[j] != ' ' && (j != 0 || str[j - 1] == ' '))
		{
			words_number++;
		}
	}
tokens_array = malloc(words_number * sizeof(char *));
	if (tokens_array == NULL)
	return (NULL);
token = strtok(str, " ");
	while (token)
	{
		tokens_array[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
return (tokens_array);
}
/**
*exec_loop- executes the prompt for interacting with the process
*@program_name: argv[0]
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
*exec_command-Executes the command if it is valid
*@command: Command passed as argument to be executed
*@program_name: argv[0]
*Return: Nothing void
*/
void exec_command(char *command, char *program_name)
{
char **tokens;
int id, status;
tokens = split_string(command);
	if (tokens == NULL)
	{
		return;
	}
id = fork();
	if (id != 0)
	{
		wait(&status);
	}
else
	{
	if (execve(tokens[0], tokens, NULL) == -1)
	{
		printf("%s: No such file or directory\n", program_name);
	}
}
free(tokens);
}
/**
*exec_no_loop- Executes in non interactive mode
*@program_name: argv[0]
*Return: Nothing void
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
else
perror("message d'erreur");
free(command);
return (0);
}
