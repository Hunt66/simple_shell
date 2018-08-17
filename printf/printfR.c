#include <stdarg.h>
#include "holberton.h"

/**
 * _printfR - print rot13 cypher of string
 * @args: list of arguments
 *
 * Description: Function takes a string and prints its rot13
 * cypher
 * Return: number of char printed
 */
int _printfR(va_list args)
{
	char *s = va_arg(args, char *);
	char rot[53] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char alpha[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, j, len, match = 0;

	if (!s)
		s = "(null)";

	len = _strlen(s);

	for (i = 0; s[i]; i++)
	{
		for (j = 0; alpha[j]; j++)
		{
			if (s[i] == alpha[j])
			{
				_putchar(rot[j]);
				match = 1;
				break;
			}
		}

		if (!match)
			_putchar(s[i]);

		match = 0;
	}

	return (len);
}
