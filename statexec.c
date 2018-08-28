#include "holberton_shell.h"

/**
 *stat_exec- checks if command exists and executes it if it does
 *@argv: the array of commands
 *@line: the line argv was made from (only to free)
 *@i: number of lines in shell
 *@env: environment
 *Return: 0 if success, -1 if need to break
 */
int stat_exec(char **argv, char *line, size_t i, char **env)
{
	struct stat st;
	char *path = "_";
	char *envi = _getenv(path, env);
	(void)line;

	if (stat(argv[0], &st) != 0)
	{
		write(1, envi, _strlen(envi) + 1);
		write(1, ": ", 2);
		print_number(i);
		write(1, ": ", 2);
		write(1, argv[0], strlen(argv[0]) + 1);
		write(1, ": not found\n", 12);
	}
	else
	{         /*execute command*/
		if (execve(argv[0], argv, NULL) == -1 && isatty(0))
		{
			write(1, envi, _strlen(envi) + 1);
			write(1, ": ", 2);
			print_number(i);
			write(1, ": ", 2);
			write(1, argv[0], strlen(argv[0]) + 1);
			write(1, ": not found\n", 12);
		}
	}
	return (0);
}


/**
 *builtin- checks if the user input a built-in command and executes it
 *@env: the current environment
 *@argv: the list of arguments provided
 *@line: the line from getline
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
		free_shell(argv, line);
		return (1);
	}
	else if (_strcmp("exit", argv[0]) == 0)/*exit*/
	{
		free_shell(argv, line);
		if (argv[1] == NULL)
			exit(0);
		exit(atoi(argv[1]));
	}
	return (0);
}
