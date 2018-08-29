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
	int i;      /*variables*/
	char *str = malloc(_strlen(st) + 1);
	int spaces = -1;
	char *token;
	char **tokens;

	for (i = 0 ; st[i] != '\0' ; i++)
	{
		if (st[i] != ' ' && st[i] != '\n')
		{
			spaces = 1; /*checking if command is just spaces*/
			break;
		}
	}
	if (spaces == -1)
	{
		free(str);
		return (NULL);
	}
	_strcpy(str, st);
	for (i = 0 ; str[i] ; i++)/*counts spaces or newlines in string*/
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == ':')
		{
			spaces++;
		}
	}
	tokens = malloc(sizeof(char *) * spaces + 1);
	token = strtok(str, dil);/*sepperates st into an array of strings*/
	for (i = 0 ; token != NULL ; i++)
	{
		tokens[i] = malloc(_strlen(token) + 1);
		tokens[i] = _strcpy(tokens[i], token);
		token = strtok(NULL, dil);
	}
	tokens[i] = NULL;
	free(token);	/*free and return*/
	free(str);
	return (tokens);
}
