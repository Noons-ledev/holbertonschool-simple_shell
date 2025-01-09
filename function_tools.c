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
	int i = 0, words_number = 0;
	size_t j = 0;
	size_t len = strlen(str);
	if (str == NULL)
		return (NULL);
	for (; j < len; j++)
	{
		if ((j == 0 || str[j - 1] == ' ') && str[j] != ' ')
			words_number++;
	}
	tokens_array = malloc((words_number + 1) * sizeof(char *));
	if (tokens_array == NULL)
		return (NULL);
	token = strtok(str, " ");
	while (token)
	{
		tokens_array[i] = strdup(token);
		if (tokens_array[i] == NULL)
		{
			while (i >= 0)
			{
				free(tokens_array[i - 1]);
				i--;
			}
			free(tokens_array);
			return (NULL);
		}
		token = strtok(NULL, " ");
		i++;
	}
	tokens_array[i] = NULL;
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
/**
*free_tokens-frees an array of array
*@tokens: Array of array
*Return: nothing void
*/
void free_array(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);
	free(tokens);
}
/**
 *_strspn- return nb of char from str consecutively corresponding to those from models
 *@str: String passed to search on
 *@models: String used as a reference pattern
 *Return : Nb of corresponding consecutive chars
 */
size_t _strspn(char *str, char *models)
{
	char *cursor1, *cursor2 ;
	size_t count = 0;
	for (cursor1 = str; *cursor1 != '\0'; cursor1++)
		{
			for (cursor2 = models; *cursor2 != '\0'; cursor2++)
			{
				if (*cursor1 == *cursor2)
				break;
			}
			if (*cursor2 == '\0')
			return (count);

			count++;
		}
		return (count);
}
