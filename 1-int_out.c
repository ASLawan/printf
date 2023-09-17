#include "main.h"

/**
 * print_int - function that Prints integer.
 * @a: The va_list containing integer.
 * Return: The number of characters printed.
 */

int print_int(va_list a)
{
	int nbr = va_arg(a, int);
	int len = 0;

	if (nbr < 0)
	{
		_putchar('-');
		nbr = -nbr;
		len++;
	}
	if (nbr == 0)
	{
		_putchar('0');
		len++;
	}
	else
	{
		int r_nbr = 0;

		while (nbr > 0)
		{
			r_nbr = (r_nbr * 10) + (nbr % 10);
			nbr /= 10;
		}
		while (r_nbr > 0)
		{
			_putchar((r_nbr % 10) + '0');
			r_nbr /= 10;
			len++;
		}
	}
	return (len);
}
