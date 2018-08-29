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
 *@argv: list of args to free
 *@line: line to free
 */
void getline_fail(char **argv, char *line)
{
	(void)argv;
	(void)line;
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * print_number - print a numner
 * @a: number to print
 * Return: Number of characters printed
 */
int print_number(size_t a)
{
	unsigned int result;
	int div = 1;
	int input, count = 0;

	input = a;

	if (input < 0)
	{
		_putchar('-');
		result = input * -1;
		count++;
	}
	else
		result = input;

	while (result / div > 9)
		div = div * 10;

	while (div != 0)
	{
		_putchar(result / div + '0');
		result = result % div;
		div = div / 10;
		count++;
	}
	return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _strdup - copies a string to a newly allocated space in memory
 * @str: the given string
 *
 * Return: a pointer to the string, or NULL if the given string is NULL
 */
char *_strdup(char *str)
{
	char *dupe = NULL;


	if (!str)
		return (NULL);

	dupe = malloc(_strlen(str) + 1);

	if (dupe == NULL)
		return (NULL);
	dupe = _strcpy(dupe, str);
	return (dupe);
}
