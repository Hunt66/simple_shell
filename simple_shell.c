#include "holberton_shell.h"

/**
 *main- runs a simple shell that Erwin and Essence created
 *
 *Return: 0 if success -1 if fails fail will often crash instead
 */


int main(void)
{
	int i;            /*variables*/
	struct stat st;
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
				if (stat(argv[0], &st) != 0)  /*check for if  */
				{                             /*command exists*/
					perror("Error2:");
				}
				else
				{         /*exicutest command*/
					if (execve(argv[0], argv, NULL) == -1)
					{
						perror("Error3:");
						break;
					}
					for (i = 0 ; argv[i] ; i++)
					{
						free(argv[i]);
					}
					free(argv);  /*freeing all in child*/
					free(line);
				}
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
	for (i = 0 ; argv[i] != NULL ; i++)
	{
		free(argv[i]);
	}
	free(argv);
	free(line);      /*free all in parent*/
	return (0);
}
