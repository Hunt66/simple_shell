#include "holberton_shell.h"


/**
 *str_concat - concatenates two strings
 *@s1: first string
 *@s2: second string
 *Return: newley allocated space in mem with s1 & s2 or NULL if fails
 */


char *str_concat(char *s1, char *s2)
{
	unsigned int i, j, size;
	char *out;

	if (s1 != NULL)
		for (i = 0 ; s1[i] != '\0' ; i++)
			;
	else
		i = 0;
	if (s2 != NULL)
		for (j = 0 ; s2[j] != '\0' ; j++)
			;
	else
		j = 0;
	size = i + j;
	out = (char *)malloc(sizeof(char) * size + 1);
	if (out == NULL)
		return (NULL);
	j = 0;
	if (s1 != NULL)
	{
		for (j = 0 ; j < i ; j++)
		{
			out[j] = s1[j];
		}
		if (s2 != NULL)
		{
			for ( ; j < size ; j++)
			{
				out[j] = s2[j - i];
			}
		}
	}
	else
	{
		if (s2 != NULL)
		{
			for (j = 0 ; j < size ; j++)
			{
				out[j] = s2[j];
			}
		}
	}
	out[j] = '\0';
	free(s1);

	return (out);
}
