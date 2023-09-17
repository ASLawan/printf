#include "main.h"

/**
 * print_bin - prints binary numbers
 * @a: unnamed arguments
 * Return: binary number
 */
int print_bin(va_list a)
{
	int i, count = 0, n;

	n = va_arg(a, int);

	for (i = 31; i >= 0; i--)
	{
		if ((n & (1 << i)) != 0)
		{
			break;
		}
	}
	for (; i >= 0; i--)
	{
		if ((n & (1 << i)) != 0)
		{
			_putchar('1');
		}
		else
		{
			_putchar('0');
		}
		count++;
	}

	return (count);
}

