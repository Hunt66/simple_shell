#include "holberton_shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: an integer less than, equal to, or greater than 0, dependent on
 * the result of the function
 */
int _strcmp(const char *s1, char *s2)
{
	int count;
	int result;

	for (count = 0; s1[count] != '\0' && s2[count] != '\0'; count++)
		if (s1[count] != s2[count])
		{
			result = s1[count] - s2[count];
			return (result);
		}
	return (0);
}

/**
 * *_getenv - gets the specified environment variable
 * @name: the name of the variable
 * @env: the environment variable
 * Return: a pointer to the variable, or NULL on failure
 */
char *_getenv(const char *name, char **env)
{
	int i, len;

	for (len = 0; name[len] != '\0'; len++)
		;

	for (i = 0; env[i]; i++)
		if (_strcmp(name, env[i]) == 0)
			return (&env[i][len + 1]);
	return (NULL);
}

/**
 **_path - appends the user input onto the PATH if necessary
 * @argc: argument count
 * @argv: the given argument
 * @env: the environment variable
 * Return: a pointer to the full argument, with PATH
 */
char **_path(int argc, char **argv, char **env)
{
	int i, j;
	char *str;
	(void)argc;

	if (!_getenv(argv[0], env))
		return (argv);
	str = _getenv(argv[0], env);

	for (i = 0; str[i] != '\0'; i++)
		;
	for (j = 0; argv[0][j] != '\0'; j++)
		str[i + j] = argv[0][j];
	str[i + j] = '\0';
	argv[0] = str;
	return (argv);
}
