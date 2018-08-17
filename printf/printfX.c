#include "holberton.h"
#include <stdlib.h>
#include<stdarg.h>

/**
 *_printfX - converts decimal input to hex and prints it
 *@args: input decimal
 *Return: count
 */
int _printfX(va_list args)
{
	unsigned int *list;
	int i, count = 0;
	unsigned int input = va_arg(args, int);

	if (input == 0)
	{
		_putchar('0');
		return (1);
	}
	list = (unsigned int *)malloc((4) * 30);
	for (i = 0 ; input > 0 ; i++)
	{
		list[i] = input % 16;
		input = input / 16;
	}
	count = i;
	for (i = i - 1 ; i >= 0 ; i--)
	{
		if (list[i] > 9)
		{
			_putchar((list[i] - 10) + 'A');
		}
		else
		{
			_putchar(list[i] + '0');
		}
	}
	return (count);
}
