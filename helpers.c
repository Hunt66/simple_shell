#include "holberton_shell.h"

/**
 *_strlen- obtains the length of a string
 *@str: string to measure
 *Return: length
 */

/*int _strlen(char *str)
{
	int i;

	for (i = 0 ; str[i] ; i++)
		;
	return (i);
}*/

/**
 *free_shell- frees all elaments of the simple shell
 *@argv: input array of string to be freed
 *@line: string line to be freed
 *Return: void
 */

void free_shell(char **argv, char *line)
{
	int i;

	for (i = 0 ; argv[i] != NULL ; i++)
	{
		free(argv[i]);
	}
	free(argv);   /*FREE*/
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
