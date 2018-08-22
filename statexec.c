#include"holberton_shell.h"

/**
 *stat_exec- checks if command exists and executes it if it does
 *@argv: the array of comands
 *@line: the line argv was made from (only to free)
 *Return: 0 if success -1 if need to break
 */


int stat_exec(char **argv, char *line)
{
	struct stat st;

	if (stat(argv[0], &st) != 0)  /*check for if  */
	{                             /*command exists*/
		perror("Error2:");
	}
	else
	{         /*exicutest command*/
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error3:");
			return (-1);
		}
		free_shell(argv, line);/*frees child*/
	}
	return (0);
}
