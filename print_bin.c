#include "main.h"

/**
 * print_bin - prints binary numbers
 * @a: unnamed arguments
 * Return: number of arguments
 */

int print_bin(va_list a)
{
	unsigned int num = va_arg(a, unsigned int);
	int count = 0, j, binary[32];

	while (num > 0)
	{
		binary[count] = num % 2;
		num /= 2;
		count++;
	}

	for (j = count - 1; j >= 0; j--)
	{
		_putchar(binary[j] + '0');
	}
	return (count);
}
