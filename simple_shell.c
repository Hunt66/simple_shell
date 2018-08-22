#include "holberton_shell.h"

/**
 *main- runs a simple shell that Erwin and Essence created
 *
 *Return: 0 if success -1 if fails fail will often crash instead
 */


int main(void)
{
	char *line;
	char **argv;
	pid_t child;
	ssize_t characters;
	size_t size = 1;
	char cwd[PATH_MAX];

	line = malloc(sizeof(char) * size);   /*malloc line (comand line)*/
	if (!line)
	{
		perror("Error0:");
		return (-1);
	}

	while (1)         /*shell runs on infinate while loop with a break*/
	{                 /*statement to close*/
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			printf("%s$ ", cwd);  /*prompt*/

			characters = getline(&line, &size, stdin);
			argv = tok(line, " \n");   /*runs tok func on getline
                                                     comand line*/
			if (characters == EOF)
				break;          /*ctrl d breaks loop*/
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
			}
			else
				wait(NULL);  /*waites for current process */
		}                            /*befor continnuing */
		else
		{                          /*if no current working directory*/
			perror("Error4:");
			return (-1);
		}
	}
	free_shell(argv, line);      /*free all in parent*/
	return (0);
}
