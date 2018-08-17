#include"holberton.h"
#include<stdlib.h>
#include<stdarg.h>

int _print_hex(unsigned long input);

/**
 *_printfpp - prints the address of a pointer
 *@args: input pointer
 *Return: number of chars printed
 */
int _printfpp(va_list args)
{
	unsigned long address;
	int count = 0;

	_putchar('0');
	_putchar('x');
	address = (unsigned long)va_arg(args, void *);

	count = _print_hex(address);
	return (count + 2);
}


/**
 * _print_hex - print hex
 * @input: input
 *
 * Return: number of chars printed
 */
int _print_hex(unsigned long input)
{
	unsigned long *list;
	int i, count = 0;

	if (input == 0)
	{
		_putchar('0');
		return (1);
	}
	list = (unsigned long *)malloc((4) * 30);
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
			_putchar((list[i] - 10) + 'a');
		}
		else
		{
			_putchar(list[i] + '0');
		}
	}
	free(list);
	return (count);
}
