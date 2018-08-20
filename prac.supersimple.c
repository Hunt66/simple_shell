#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Super simple Shell
 */
int main(void)
{
	char *line;
	char **argv;
	pid_t child;
	size_t characters, size = 1;

	line = malloc(sizeof(char) * size);
	if (!line)
	{
		perror("Error:");
		return (0);
	}

	argv[1] = NULL;
	while (1)
	{
		printf("Prompt : ");

		characters = getline(&line, &size, stdin);
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
}
