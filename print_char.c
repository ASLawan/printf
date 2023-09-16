#include "main.h"

/**
 * print_char - prints characters
 * @a: unnamed arguments
 * Return: 0 always
 */

int print_char(va_list a)
{
	char c;

	c = va_arg(a, int);
	_putchar(c);

	return (0);
}
