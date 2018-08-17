#include <stdarg.h>
#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _printfS - print string
 * @args: string argument
 *
 * Description: Function prints string, if char is not printable, print
 * ascii representation of that char
 * Return: num of char printed
 */
int _printfS(va_list args)
{
	char *s = (char *)va_arg(args, char *);
	int i, j, count = 0, num = 0, first;
	unsigned int *list;

	if (!s)
		s = "(null)";

	list = (unsigned int *)malloc((4) * 10);

	for (i = 0; s[i]; i++)
	{
		first = 1;

		if ((s[i] > 0 && s[i] < 32) || s[i] > 126)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;


			num = s[i];

			for (j = 0; num > 0; j++)
			{
				list[j] = num % 16;
				num /= 16;

				if (j > 0)
					first = 0;
			}

			for (j -= 1; j >= 0; j--)
			{
				if (first)
				{
					_putchar('0');
					count++;
				}

				if (list[j] > 9)
				{
					_putchar((list[j] - 10) + 'A');
					count++;
				}
				else
				{
					_putchar(list[j] + '0');
					count++;
				}
			}
		}

		else
		{
			_putchar(s[i]);
			count++;
		}
	}

	free(list);
	return (count);
}
