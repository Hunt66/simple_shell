#include "holberton_shell.h"

/**
 * Simple Shell
 */
int main(void)
{
	int i;
	struct stat st;
	char *line;
	char **argv;
	pid_t child;
	ssize_t characters;
	size_t size = 1;
	char cwd[PATH_MAX];

	line = malloc(sizeof(char) * size);
	if (!line)
	{
		perror("Error0:");
		return (0);
	}

	while (1)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			printf("%s$ ", cwd);

			characters = getline(&line, &size, stdin);
			argv = tok(line, " \n");

			if (characters == EOF)
				break;
			for (i = 0 ; line[i] ; i++)
				if (line[i] == '\n')
					line[i] = '\0';
			(void)characters;

			child = fork();
			if (child == -1)
			{
				perror("Error1:");
				return (0);
			}
			if (child == 0)
			{
				if (stat(argv[0], &st) != 0)
				{
					perror("Error2:");
				}
				else
				{
					if (execve(argv[0], argv, NULL) == -1)
					{
						perror("Error3:");
						break;
					}
					for (i = 0 ; argv[i] ; i++)
					{
						free(argv[i]);
					}
					free(argv);
					free(line);
				}
			}
			else
				wait(NULL);
		}
		else
		{
			perror("Error4:");
			return (-1);
		}
	}
	for (i = 0 ; argv[i] != NULL ; i++)
	{
		free(argv[i]);
	}
	free(argv);
	free(line);
	return (0);
}
