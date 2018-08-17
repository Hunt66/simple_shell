#include <stdarg.h>
#include "holberton.h"

/**
 * _printfr - reverse a given string
 * @args: string argument
 *
 * Description: Function takes a string and reverses it
 * Return: number of chars printed
 */
int _printfr(va_list args)
{
	char *s = va_arg(args, char *);
	int i, len = 0;


	if (!s)
		s = "(null)";

	len = _strlen(s);
	i = len - 1;

	for (; i >= 0; i--)
		_putchar(s[i]);

	return (len);
}
