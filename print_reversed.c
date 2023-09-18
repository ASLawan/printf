#include "main.h"

/**
 * print_reversed - prints string in reverse
 * @a: unnamed arguments
 * Return: string
 */
int print_reversed(va_list a)
{
	int i, len_str = 0;
	char *rev_str = va_arg(a, char*);

	if (rev_str == NULL)
	{
		rev_str = "(null)";
	}
	
	len_str += str_len(rev_str);
	
	for (i = len_str - 1; i >= 0; i--)
	{
		_putchar(rev_str[i]);
	}
	return (len_str);
}
