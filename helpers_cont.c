#include "holberton_shell.h"

/**
 * sighelp - prints a newline and then the prompt
 * @a: dummy variable
 */
void sighelp(int a)
{
	(void)a;

	write(1, "\n", 1);
	prompt(1);
}

/**
 * getline_fail - writes a new line and then frees
 */
void getline_fail(char **argv, char *line)
{
	write(STDOUT_FILENO, "\n", 1);
	free_shell(argv, line);   /*ctrl-d test 0*/
	exit(7);
}
