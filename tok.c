#include "holberton_shell.h"

/**
 *tok- accepts a string and string delimiter and breaks the string into
 * an array of words using strtok (only works for certain dilimiters)
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
	char *str = _strdup(st);
	int spaces = -1;
	char *token = NULL;
	char **tokens = NULL;

	for (i = 0 ; st[i] != '\0' ; i++)
	{
		if (st[i] != ' ' && st[i] != '\n')
		{
			spaces = 1; /*checking if command is just spaces*/
			break;
		}
	}
	if (spaces == -1)
		return (NULL);
	for (i = 0 ; str[i] ; i++)/*counts spaces or newlines in string*/
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == ':')
			spaces++;
	}
	tokens = malloc(sizeof(char *) * (spaces + 1));
	token = strtok(str, dil);/*separates st into an array of strings*/
	for (i = 0 ; token != NULL ; i++)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, dil);
	}
	tokens[i] = NULL;
	free(str);
	return (tokens);
}
