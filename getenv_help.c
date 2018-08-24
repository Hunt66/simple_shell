#include "holberton_shell.h"



/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
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
	int i, k, j = 0;
	char *path = "PATH";
	char *str;
	char **strs;
	struct stat st;
	(void)argc;

	str = _getenv(path, env); /*gets the env*/
	strs = tok(str, ":"); /* separates the tokens*/
	for (k = 0 ; strs[k] != NULL ; k++)
	{
		/*iterates to the end of a given element in the array*/
		for (i = 0; strs[k][i] != '\0'; i++)
			;
		strs[k][i] = '/';

		/*appends the command the user
		  types to the gotten path element*/
		for (j = 0 ; argv[0][j] != '\0' ; j++)
		{
			strs[k][i + j + 1] = argv[0][j];
		}

		strs[k][i + j + 1] = '\0';
		/*checks to see if the command exists*/
		if (stat(strs[k], &st) == 0)
		{
			_strcpy(argv[0], strs[k]);
			/*frees everything*/
			for (i = 0 ; strs[i] != NULL ; i++)
				free(strs[i]);
			free(strs);
			return (argv);
		}
	}
	return (argv);
}
