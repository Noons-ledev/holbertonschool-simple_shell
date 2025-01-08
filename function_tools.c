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
	tokens_array = malloc((words_number + 1) * sizeof(char *));
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
 *remove_newline- removes newline from a string
 *@str: string as arg
 *Return: nothing void
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
/**
 *_getenv-get the value of an environment variable
 *@name: Name of the variable to get its value
 *Return: Pointer to the value of the variable
 */
char *_getenv(const char *name)
{
	int i = 0;

	size_t name_len = strlen(name);

	if (name == NULL || environ == NULL)
	{
		return (NULL);
	}
	while (environ[i])
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
		i++;
	}
	return (NULL);
}
