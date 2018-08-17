#include <stdarg.h>
#include "holberton.h"

/**
 * print_un - print unsigned int one char at a time
 * @num: unsigned num
 *
 * Description: Function prints num one char at a time
 * Return: num of char printed
 */
int print_un(unsigned int num)
{
	int len = 0;

	if (num < 10)
	{
		_putchar(num + '0');
		return (1);
	}

	len = 1 + print_un(num / 10);

	_putchar(num % 10 + '0');

	return (len);
}

/**
 * _printfu - print unsigned int
 * @args: unsigned int argument
 *
 * Description: Function prints unsigned int
 * Return: number of digits printed
 */
int _printfu(va_list args)
{
	unsigned int i = va_arg(args, int);

	return (print_un(i));
}
