#include "holberton_shell.h"

/**
 *tok- accepsts a string and string dilimiter and breaks the string into
 *     an array of words using strtok (only works for certain dilimiters)
 *
 *accepted delimiters: " ", "\n" and ":" so far
 *
 *@st: the string to be altered
 *@dil:The dilimiter to break strings by
 *Return: An array of strings
 */

char **toks(char *st, char *dil)
{
	int i, j = 0;                             /*variables*/
	char *str = malloc(_strlen(st) + 1);
	int dils = 1;
	char **tokens;
	(void)dil;
	strcpy(str, st);
	for (j = 0 ; str[j] == ' ' || str[j] == ':'|| str[j] == '\n' ; j++)
		;  /*moving to first letter*/
	for (i = j ; str[i] != '\0' ; i++) /*counting accepted dils*/
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == ':')
		{
			if (str[i] == '\n')
				str[i] = ' ';
			dils++;
		}
	}
	if (_strlen(st) == dils - 1) /*if nothing but disl return NULL*/
	{
		printf("NULL check\n");
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * (dils + 1));
	dils = 0;
	i = j;
	j = 0;
	printf("%d\n", i);
	printf("i%si\n", str);
	tokens[dils] = malloc(42);
	for (i = i ; str[i] != '\0' ; i++)/*sepperates st into an array of strings*/
	{
		printf("%c\n", str[i]);
		if (str[i] == ' ' || str[i] == '\n' || str[i] == ':')
		{
			printf("dil\n");
			tokens[dils][j] = '\0';
			dils++;
			j = 0;
			continue;
		}
		tokens[dils][j] = str[i];
		printf("j%c\n", tokens[dils][j]);
		j++;
	}
	tokens[dils] = NULL;
	free(str); /*free and return*/
	for (i = 0 ; tokens[i] ; i++)
	{
		printf("%s\n", tokens[i]);
			}
	return (tokens);
}
