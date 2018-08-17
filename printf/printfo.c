#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _printfo - print octal
 * @args: integer input
 *
 * Return: number of characters printed
 */
int _printfo(va_list args)
{

	int count, i;
	unsigned long int num = va_arg(args, unsigned int);
	unsigned long int eight = 8;
	int *hold_num = malloc((4) * 30);


	for (i = 0; num > 0; num /= eight, i++)
	{
		hold_num[i] = (num % eight);
	}

	for (count = i - 1; count >= 0; count--)
		_putchar(hold_num[count] + '0');
	free(hold_num);
	return (i);

}
