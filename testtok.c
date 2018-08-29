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
	char *str = strdup(st);
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
		return (NULL);
	_strcpy(str, st);
	for (i = 0 ; str[i] ; i++)/*counts spaces or newlines in string*/
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == ':')
			spaces++;
	}
	printf("%i\n", spaces);
	tokens = malloc(sizeof(char *) * (spaces + 1));
	token = strtok(str, dil);/*separates st into an array of strings*/
	for (i = 0 ; token != NULL ; i++)
	{
		printf("%s\n", token);
		/*tokens[i] = malloc(_strlen(token) + 1);*/
		tokens[i] = strdup(token);
		token = strtok(NULL, dil);
	}
	tokens[i] = NULL;
	free(str);
	return (tokens);
}

int main(void)
{
	char *a = "This is a test";
	char **b;
	int i = 0;

	b = tok(a, " ");

	while (b[i] != NULL)
	{
		write(1, b[i], strlen(b[i]));
		i++;
	}
	i = 0;
	while (b[i] != NULL)
	{
		free(b[i]);
		i++;
	}
	free(b);
	return (0);
}
