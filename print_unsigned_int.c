#include "main.h"

/**
 * print_c - prints character
 * @n: character argument
 * Return: nothing
 */
void print_c(unsigned int n)
{
	if (n == 0)
	{
		return;
	}
	print_c(n / 10);
	_putchar((n % 10) + '0');
}
/**
 * print_unsigned - prints unsigned integers
 * @a: unnamed arguments
 * Return: number of characters printed
 */

int print_unsigned(va_list a)
{
	int count = 0;
	unsigned int n = va_arg(a, unsigned int);

	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		unsigned int temp = n;

		while (temp != 0)
		{
			temp /= 10;
			count++;
		}
		print_c(n);
	}
	return (count);
}
