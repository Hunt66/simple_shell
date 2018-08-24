#include "holberton_shell.h"

/**
 *stat_exec- checks if command exists and executes it if it does
 *@argv: the array of commands
 *@line: the line argv was made from (only to free)
 *Return: 0 if success, -1 if need to break
 */
int stat_exec(char **argv, char *line)
{
	struct stat st;

	if (stat(argv[0], &st) != 0)  /*check if command is valid*/
	{
		perror("Error2:");
	}
	else
	{         /*execute command*/
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error3:");
		}
		free_shell(argv, line); /*frees child*/
	}
	return (0);
}
