#include "holberton_shell.h"

/**
 *main- runs a simple shell
 * @ac: unused variable
 * @av: unused variable
 * @env: the environment variable
 *Return: 0 if successful, -1 on failure
 */
int main(int ac, char **av, char **env)
{
	char **argv, *line = NULL;
	pid_t child;
	ssize_t characters = 0;
	size_t size = 0;
	char cwd[PATH_MAX];
    	(void)ac;
	(void)av;

	while (characters != -1)
	{
		free(line);
		size = 0;
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			_printf("%s$ ", cwd);  /*prompt*/
			characters = getline(&line, &size, stdin);
			fflush(stdin);
			if (characters == -1)
			{
				write(STDOUT_FILENO, "\n", 1);
				free_shell(argv, line);
				exit(7);
			}
			argv = tok(line, " \n");   /*runs tok func on line*/
			if (argv == NULL)
				continue;
			argv = _path(1, argv, env);
			(void)characters;

			child = fork();        /*creates and checks child*/
			if (child == -1)
			{
				perror("Error1:");
				return (-1);
			}
			if (child == 0)
			{
				if (stat_exec(argv, line) == -1)
					break;
				free_shell(argv, line);
				exit(1);
			}
			else
				wait(NULL);  /*waits for current process */
		}                            /*before continuing */
		else
		{                          /*if no current working directory*/
			perror("Error4:");
			return (-1);
		}
	}
	if (argv != NULL)
		free_shell(argv, line);      /*free all in parent*/
	return (0);
}
