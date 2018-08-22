#include "holberton_shell.h"

/**
 * Super simple Shell
 */
int main(void)
{
	int i;
	char *line;
	char **argv = malloc(sizeof(char*) * 2);
	pid_t child;
	ssize_t characters;
	size_t size = 1;

	line = malloc(sizeof(char) * size);
	if (!line)
	{
		perror("Error:");
		return (0);
	}

	while (1)
	{
		printf("Prompt : ");

		characters = getline(&line, &size, stdin);
		for (i = 0 ; line[i] ; i++)
			if (line[i] == '\n')
				line[i] = '\0';
		(void)characters;
		argv[0] = line;
		printf("%s\n", argv[0]);
		child = fork();
		if (child == -1)
		{
			perror("Error:");
			return (0);
		}
		if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
			wait(NULL);
	}
	return (0);
}
