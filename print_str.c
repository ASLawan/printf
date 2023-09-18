#include "main.h"

/**
 * print_str - prints strings
 * @a: unnamed arguments
 * Return: number of characters
 */

int print_str(va_list a)
{
	int i, count;
	char *str = va_arg(a, char *);

	if (str == NULL)
	{
		str = "(null)";
		count = str_len(str);
		for (i = 0; i < count; i++)
		{
			_putchar(str[i]);
		}
	}
	else
	{
		count = str_len(str);
		for (i = 0; i < count; i++)
		{
			_putchar(str[i]);
		}
	}
	return (count);

}
