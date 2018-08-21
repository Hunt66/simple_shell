#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "holberton_shell.h"


/**
 *_strtok- takes a string and seperates the string by spaces
 *@str: the string to be altered
 *@delim: the diliminator will alwayse be a space
 *Return: pointer to the string
 */


char *_strtok(char *str, const char *delim)
{

	static char *olds;
	char *nstr = "";
	int i, j;


	if (str == NULL)
	{
		return (_strtok(olds, delim));
	}


	for (j = 0 ; str[j] != '\0' ; j++)
		;

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '\0';
			break;
		}
	}

	nstr = malloc(j - i + 1);

	for (j = 0 ; str[i + 1] != '\0' ; i++, j++)
	{
		nstr[j] = str[i + 1];
	}
	nstr[j] = str[i + 1];


	olds = nstr;


	return (str);
}
