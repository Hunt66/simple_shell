#include "holberton_shell.h"

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
