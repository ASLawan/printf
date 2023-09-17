#include "main.h"

/**
 * print_octal - prints octal numbers
 * @a: unnamed arguments
 * Return: num of characters
 */

int print_octal(va_list a)
{
	int  count = 0, i;
	unsigned int n = va_arg(a, unsigned int);
	unsigned int tmp_octal = n;
	int *octal;

	while (n / 8 != 0)
	{
		n /= 8;
		count++;
	}
	count++;

	octal = malloc(count * sizeof(int));

	if (octal == NULL)
	{
		free(octal);
		return (0);
	}
	for (i = 0; i < count; i++)
	{
		octal[i] = tmp_octal % 8;
		tmp_octal /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(octal[i] + '0');
	}
	free(octal);
	return (count);
}

