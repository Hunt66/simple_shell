#include "holberton_shell.h"

/**
 *tok- accepsts a string and string dilimiter and breaks the string into
 *     an array of words using strtok (only works for certain dilimiters)
 *
 *accepted delimiters: " ", "\n" so far
 *
 *@st: the string to be altered
 *@dil:The dilimiter to break strings by
 *Return: An array of strings
 */

char **tok(char *st, char *dil)
{
	/*variables*/
	int i;
	char *str = malloc(strlen(st) + 1);
	int spaces = 1;
	char *token;
	char **tokens;

	strcpy(str, st);

	/*counts spaces or newlines in string*/
	for (i = 0 ; str[i] ; i++)
	{
		if (str[i] == ' ' || str[i] == '\n')
		{
			spaces++;
		}
	}
	tokens = malloc(sizeof(char*) * spaces);

	/*sepperates st into an array of strings*/
	token = strtok(str, dil);
	for (i = 0 ; token != NULL ; i++)
	{
		tokens[i] = malloc(strlen(token) + 1);
		tokens[i] = strcpy(tokens[i], token);
		token = strtok(NULL, dil);
	}
	tokens[i] = NULL;

	/*free and return*/
	free(token);
	free(str);
	return (tokens);
}
