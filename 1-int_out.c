#include "main.h"

/**
 * print_int - function that Prints int.
 * @a: The va_list containing int.
 * Return: The number of characters printed.
 */

int print_int(va_list a)
{
	int num = va_arg(a, int);
	int len = 0;

    /* Print the integer */
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		len++;
	}
	if (num == 0)
	{
		_putchar('0');
		len++;
	}
	else
	{
		int r_num = 0;

		while (num > 0)
		{
			r_num = (r_num * 10) + (num % 10);
			num /= 10;
		}
		while (r_num > 0)
		{
			_putchar((r_num % 10) + '0');
			r_num /= 10;
			len++;
		}
	}
	return (len);
}
