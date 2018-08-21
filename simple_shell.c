#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include "holberton_shell.h"

/**
 * Super simple Shell
 */
int main(void)
{
	int i;
	struct stat st;
	char *line;
	char **argv = malloc(sizeof(char*) * 2);
	pid_t child;
	ssize_t characters;
	size_t size = 1;
	char cwd[PATH_MAX];

	line = malloc(sizeof(char) * size);
	if (!line)
	{
		perror("Error:");
		return (0);
	}

	argv[1] = NULL;
	while (1)
	{
		characters = 0;
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			printf("%s$ ", cwd);

			characters = getline(&line, &size, stdin);
			if (characters == EOF)
				break;
			for (i = 0 ; line[i] ; i++)
				if (line[i] == '\n')
					line[i] = '\0';
			(void)characters;
			argv[0] = line;
			child = fork();
			if (child == -1)
			{
				perror("Error:");
				return (0);
			}
			if (child == 0)
			{
				if (stat(argv[0], &st) == 0)
				{
					if (execve(argv[0], argv, NULL) == -1)
						perror("Error:");
				}
				else
				{

					printf("No comand %s\n", argv[0]);
				}
			}
			else
				wait(NULL);
		}
		else
		{
			perror("Error:");
			return (-1);
		}
	}
	return (0);
}
