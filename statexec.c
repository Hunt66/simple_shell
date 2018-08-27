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
		free_shell(argv, line); /*frees child*/
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


/**
 *builtin- checks if the user input a built in command and exicutes it
 *@env: the current environment
 *@argv: the list of arguments provided
 *Return: 1 if builtin 0 if not
 */

int builtin(char **env, char **argv, char *line)
{
	int i;

	if (_strcmp("env", argv[0]) == 0)/*envronment*/
	{

		for (i = 0 ; env[i] ; i++)
		{
			write(1, env[i], _strlen(env[i]));
			write(1, "\n", 1);
		}
	       	return (1);
	}
	if (_strcmp("exit", argv[0]) == 0)/*exit*/
	{
		free_shell(argv, line);
		if (argv[1] == NULL)
			exit(0);
		exit(atoi(argv[1]));
	}
	return (0);
}
