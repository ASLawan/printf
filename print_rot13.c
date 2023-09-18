#include "main.h"

/**
 * rot13 - implements rot 13
 * @c: character
 * Return: int
 */

int rot13(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (((c - 'a' + 13) % 26) + 'a');
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (((c - 'A' + 13) % 26) + 'A');
	}
	else
	{
		return (c);
	}
}

/**
 * print_rot13 - prints rot 13
 * @a: unnamed arguments
 * Return: number of characters
 */

int print_rot13(va_list a)
{
	int count = 0, i, c;
	const char *str = va_arg(a, const char*);

	for (i = 0; str[i] != '\0'; i++)
	{
		c = rot13(c);
		_putchar(c);
		count++;
	}
	return (0);
}
