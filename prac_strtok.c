#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



/**
 *_strtok- takes a string and seperates the string by spaces
 *@str: the string to be altered
 *@delim: the diliminator will alwayse be a space
 *Return: pointer to the string
 */


char *_strtok(char *str, const char *delim)
{
	int i;



	if (str == NULL)
	{
		
	}

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '\0';
			break;
		}
	}



	return (str);
}
