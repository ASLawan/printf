#include "main.h"


/**
 * print_hex - print hex numbers
 * @a: unnamed arguments
 * Return: number of characters
 */
int print_hex(va_list a)
{
	int len = 0, i = 0;
	unsigned int hex_n = va_arg(a, unsigned int);
	unsigned int tmp_hex_n = hex_n;
	int *hex;


	while ((hex_n / 16) != 0)
	{
		hex_n /= 16;
		len++;
	}
	len++;
	hex = malloc(len * sizeof(int));

	if (hex == NULL)
	{
		free(hex);
		return (0);
	}

	while (i < len)
	{
		hex[i] = tmp_hex_n % 16;
		tmp_hex_n /= 16;
		i++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (hex[i] > 9)
		{
			hex[i] += 39;
		}
		_putchar(hex[i] + '0');
	}
	free(hex);

	return (len);
}
