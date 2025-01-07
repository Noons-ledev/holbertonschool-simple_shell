#include "main.h"

/**
 * count_words - Count the number of words in a string
 * @str: The input string
 *
 * Return: Number of words
 */
static int count_words(const char *str)
{
	int size = 1;
	int word_found = 0;
	int j;

	for (j = 0; str[j]; j++)
	{
		if (str[j] != ' ')
		{
			if (!word_found)
			{
				size++;
				word_found = 1;
			}
		}
		else
			word_found = 0;
	}
	return (size);
}

/**
 * free_tokens - Free memory allocated for tokens
 * @tokens: Array of strings to free
 * @count: Number of tokens to free
 */
static void free_tokens(char **tokens, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(tokens[i]);
	free(tokens);
}

/**
 * split_string - Split a string into several words
 * @str: The string to split
 *
 * Return: Array of strings (words from the string), or NULL on failure
 */
char **split_string(char *str)
{
	char **tokens;
	char *token;
	char *str_cpy;
	int i = 0;
	int size;

	if (!str)
		return (NULL);

	str_cpy = strdup(str);
	if (!str_cpy)
		return (NULL);

	size = count_words(str);
	tokens = malloc(size * sizeof(char *));
	if (!tokens)
	{
		free(str_cpy);
		return (NULL);
	}

	token = strtok(str_cpy, " \n");
	while (token)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			free_tokens(tokens, i);
			free(str_cpy);
			return (NULL);
		}
		token = strtok(NULL, " ");
		i++;
	}

	tokens[i] = NULL;
	free(str_cpy);
	return (tokens);
}
