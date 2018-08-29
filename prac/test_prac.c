#include "holberton_shell.h"

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
	int i, k;
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
		strs[k] = str_concat(strs[k], "/");
		/*appends the command the user*/
		/* types to the gotten path element*/
		strs[k] = str_concat(strs[k], argv[0]);
		/*checks to see if the command exists*/
		if (stat(strs[k], &st) == 0)
		{
			argv[0] = _strdup(strs[k]);
			/*frees everything*/
			for (i = 0 ; strs[i] != NULL ; i++)
				free(strs[i]);
			free(strs);


			return (argv);
		}
	}
	for (i = 0 ; strs[i] != NULL ; i++)
		free(strs[i]);


	free(strs);
	return (argv);
}


int main(int ac, char **av, char **env)
{
	char **argv = malloc(sizeof(char *) * 3);
	int i;
	(void)ac;
	(void)av;

	argv[0] = _strdup("ls");
	argv[1] = _strdup("-l");
	argv[2] = NULL;

	argv = _path(1, argv, env);

	for (i = 0 ; argv[i] != NULL ; i++)
	{
		printf("%s\n", argv[i]);
	}
	for (i = 0 ; argv[i] != NULL ; i++)
	{
		free(argv[i]);
	}
	free(argv);
	return (0);
}
