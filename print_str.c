#include "main.h"

/**
 * print_str - prints strings
 * @a: unnamed arguments
 * Return: number of characters
 */

int print_str(va_list a)
{
	int i, len;
	char *s = va_arg(a, char *);

	if (s == NULL)
	{
		s = "(nil)";
		len = str_len(s);
		for (i = 0; i < len; i++)
		{
			_putchar(s[i]);
		}
	}
	else
	{
		len = str_len(s);
		for (i = 0; i < len; i++)
		{
			_putchar(s[i]);
		}
	}
	return (len);

}
