#include "holberton_shell.h"

char **tok(char *st, char *dil)
{
	int i;
	char *str = malloc(strlen(st) + 1);
	int spaces = 1;
	char *token;
	char **tokens;

	strcpy(str, st);
	for (i = 0 ; str[i] ; i++)
	{
		if (str[i] == ' ' || str[i] == '\n')
		{
			spaces++;
		}
	}
	tokens = malloc(sizeof(char*) * spaces);
	token = strtok(str, dil);
	for (i = 0 ; token != NULL ; i++)
	{
		tokens[i] = malloc(sizeof(token));
		tokens[i] = strcpy(tokens[i], token);
		token = strtok(NULL, dil);
	}
	tokens[i] = NULL;
	free(token);
	free(str);
	return (tokens);
}
