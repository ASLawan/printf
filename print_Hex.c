#include "main.h"


/**
 * print_Hex - print hex numbers with
 * uppercase alphabet
 * @a: unnamed arguments
 * Return: number of characters
 */
int print_Hex(va_list a)
{
	int len = 0, i = 0;
	unsigned int Hex_n = va_arg(a, unsigned int);
	unsigned int tmp_Hex_n = Hex_n;
	int *Hex;


	while ((Hex_n / 16) != 0)
	{
		Hex_n /= 16;
		len++;
	}
	len++;
	Hex = malloc(len * sizeof(int));

	if (Hex == NULL)
	{
		free(Hex);
		return (0);
	}

	while (i < len)
	{
		Hex[i] = tmp_Hex_n % 16;
		tmp_Hex_n /= 16;
		i++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (Hex[i] > 9)
		{
			Hex[i] += 7;
		}
		_putchar(Hex[i] + '0');
	}
	free(Hex);

	return (len);
}
