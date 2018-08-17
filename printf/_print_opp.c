#include"holberton.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *_printfc - prints an input char
 *@args: the input char
 *Return: 0 if does not fail
 */
int _printfc(va_list args)
{
	_putchar((char)va_arg(args, int));
	return (1);
}

/**
 *_printfs- prints an input string
 *@args: input string
 *Return: 0 if does not fail
 */
int _printfs(va_list args)
{
	int i;
	char *str = (char *)va_arg(args, char *);

	if (!str)
		str = "(null)";

	for (i = 0 ; str[i] ; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}

/**
 * _printfp - prints % char
 * @args: ist of args
 *
 * Description: prints %
 * Return: characters printed
 */
int _printfp(va_list args)
{
	(void) args;

	_putchar('%');
	return (1);
}

/**
 *  _putchar - writes the character c to stdout
 *  @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - find len of str
 * @s: input str
 *
 * Description: Find length of str
 * Return: len of str
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len]; len++)
		;

	return (len);
}
