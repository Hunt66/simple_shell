#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 *exicutes the command ls -l /tmp in 5 diffrent child processes
 */

int main(void)
{
	pid_t my_pid;
	pid_t child_pid;
	int status;
	int i;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("ERROR:");
		return (1);
	}
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);


	for (i = 0 ; i < 5 ; i++)
	{
		printf("(%u) %u, I am your father\n",my_pid, child_pid);
		if (child_pid == 0)
		{
			printf("Before execve\n");
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("ERROR:");
			}
			printf("After execve\n");
		}
		else
		{
			wait(&status);
			child_pid = fork();
		}
	}
	return (0);
}
