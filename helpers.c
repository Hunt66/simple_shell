#include "holberton_shell.h"

/**
 *_strlen- obtains the length of a string
 *@str: string to measure
 *Return: length of string
 */
int _strlen(char *str)
{
	int len;

	for (len = 0 ; str[len] ; len++)
		;
	return (len);
}

/**
 *free_shell- frees all elements of the simple shell
 *@argv: input array of string to be freed
 *@line: string line to be freed
 *Return: void
 */
void free_shell(char **argv, char *line)
{
	int i;

	if (argv != NULL)
	{
		for (i = 0 ; argv[i] != NULL ; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
	if (line != NULL)
		free(line);
}

/**
 * *_strcpy - copies the string pointed to by src to the buffer
 * pointed to by dest.
 * @dest: buffer string should be copied to
 * @src: string given
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: an integer less than, equal to, or greater than 0, dependent on
 * the result of the function
 */
int _strcmp(const char *s1, char *s2)
{
	int count;
	int result;

	for (count = 0; s1[count] != '\0' && s2[count] != '\0'; count++)
		if (s1[count] != s2[count])
		{
			result = s1[count] - s2[count];
			return (result);
		}
	return (0);
}

/**
 * prompt - prints a new prompt
 *@a: does nothing
 *
 * Return: 0 on success, 1 on failure
 */
void prompt(int a)
{
	(void)a;

	if (isatty(0))
	{
		write(STDOUT_FILENO, "Conch $ ", 8);
	}
}
