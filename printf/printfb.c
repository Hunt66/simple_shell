#include "holberton.h"
#include <limits.h>
/**
 * _printfb - prints binary from decimal
 *@args: the input decimal number
 *Return: count of digets
 */


int _printfb(va_list args)
{
	unsigned long int decimal = (unsigned int)va_arg(args, int);
	unsigned long int div;
	int count = 0;

	if (decimal == 0)
	{
		_putchar('0');
		return (1);
	}
	for (div = 1 ; div <= decimal ; div = div * 2)
		;
	for (div = div / 2 ; div > 1 ; div = div / 2)
	{
		_putchar((decimal / div) + '0');
		decimal = (decimal % div);
		count++;
	}
	_putchar((decimal / div) + '0');
	count++;
	return (count);
}
