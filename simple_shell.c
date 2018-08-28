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
	size_t i;
	(void)ac;
	(void)av;

	signal(SIGINT, sighelp);

	for (i = 1; characters != -1; i++)
	{
		/*free(line);*/
		size = 0;
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			characters = -1;
			prompt(1);
			characters = getline(&line, &size, stdin);
			fflush(stdin);         /*get commands in line*/
			if (characters == -1)
			{
				getline_fail(argv , line);
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
				free_shell(argv, line);
				return (-1);
			}
			if (child == 0)
			{
				stat_exec(argv, line, i, env);/*runs command*/
				exit(1);
			}
			else
			{
				free_shell(argv, line);
				wait(NULL);  /*waits for current process */
			}
		}
		else
			return (-1);
	}
	if (argv != NULL)
		free_shell(argv, line);      /*free all in parent*/
	return (0);
}
