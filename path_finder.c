#include "main.h"

/**
 * find_command_path - find the path to the command from the user
 *
 * @command: the command
 *
 * Return: the full path or NULL
 */

char *find_command_path(char *command)
{
	char *path = getenv("PATH");
	char *dir;
	char *full_path;
	char *path_cpy;

	if (path == NULL)
		return (NULL);
	path_cpy = strdup(path);
	if (path_cpy == NULL)
		return (NULL);
	strcpy(path_cpy, path);
	full_path = malloc(strlen(path) + strlen(command) + 2);
	if (full_path == NULL)
	{
		free(path_cpy);
		return (NULL);
	}
	dir = strtok(path_cpy, ":");
	while (dir != NULL)
	{
		sprintf(full_path, "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_cpy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_cpy);
	free(full_path);
	return (NULL);
}
