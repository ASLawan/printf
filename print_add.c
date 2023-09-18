#include "main.h"
/**
 * print_hexadecimal - print hex numbers
 * @n: integer argument
 * Return: number of characters
 */
int print_hexadecimal(unsigned long int n)
{
	long int len = 0, i = 0, j;
	unsigned long int hex_n = n;
	long int *hex;

	while ((n / 16) != 0)
	{
		n /= 16;
		len++;
	}
	len++;
	hex = malloc(len * sizeof(long int));

	if (hex == NULL)
	{
		free(hex);
		return (0);
	}

	while (i < len)
	{
		hex[i] = hex_n % 16;
		hex_n /= 16;
		i++;
	}
	for (j = len - 1; j >= 0; j--)
	{
		if (hex[j] > 9)
		{
			hex[j] += 39;
		}
		_putchar(hex[j] + '0');
	}
	free(hex);

	return (len);
}
/**
 * print_address - prints pointer values
 * @a: unnamed arguments
 * Return: number of characters printed
 */
int print_address(va_list a)
{
	int count = 0, i, len = 0;
	long int addr;
	char *tmp_ptr = "(nil)";
	void  *ptr;

	ptr = va_arg(a, void*);
	if (ptr == NULL)
	{
		for (i = 0; tmp_ptr[i] != '\0'; i++)
		{
			_putchar(tmp_ptr[i]);
			len++;
		}
		return (len);
	}

	addr = (unsigned long int)ptr;
	_putchar('0');
	count += 1;
	_putchar('x');
	count += 1;
	count += print_hexadecimal(addr);
	return (count);
}
