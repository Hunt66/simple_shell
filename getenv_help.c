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

int main (int ac, char **av, char **env)
{
	char *a;
	char *b;
	(void)ac;
	(void)av;

	a = "PATH";
	b = _getenv(a, env);
	printf("%s\n", b);
	return (0);
}
