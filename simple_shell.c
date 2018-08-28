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
	char **argv = NULL, *line = NULL, cwd[PATH_MAX];
	pid_t child;
	ssize_t characters = 0;
	size_t size = 0;           /*variables*/
    	(void)ac;
	(void)av;

	signal(SIGINT, prompt);

	while (characters != -1)
	{
		free(line);
		size = 0;
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			characters = -1;
			write(1, cwd, _strlen(cwd)); /*prompt*/
			write(1, "$ ", 2);
			characters = getline(&line, &size, stdin);
			fflush(stdin);         /*get commands in line*/
			if (characters == -1)
			{
				write(STDOUT_FILENO, "\n", 1);
				free_shell(argv, line);   /*ctrl-d test 0*/
				exit(7);
			}
			argv = tok(line, " \n");   /*runs tok func on line*/
			if (argv == NULL)
				continue;
		        if (builtin(env, argv, line) == 1) /*builtins*/
				continue;
			argv = _path(1, argv, env); /*path check/append*/
			child = fork();
			if (child == -1)        /*creates and checks child*/
			{
				perror("Error1:");
				return (-1);
			}
			if (child == 0)
			{
				if (stat_exec(argv, line) == -1)/*runs command*/
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
