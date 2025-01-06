#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

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
	while	(environ[i])
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
*remove_newline- Removes the newline after getline adds it
*@str: String to remove newline from
*Return: Nothing void
*/
void remove_newline(char *str)
{
	size_t len = strlen(str);

	if ((len > 0) && (str[len - 1] == '\n'))
		str[len - 1] = '\0';
}
