#include "main.h"

/**
 * print_percent - prints percent sign
 * @a: unnamed arguments
 * Return: always 0
 */

int print_percent(va_list a)
{
	int c = va_arg(a, int);

	if(!c)
		return (0);

	_putchar('%');
	return (1);
}
