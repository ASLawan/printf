#include "main.h"
/**
 * print_Hexadecimal - print hex numbers
 * @n: integer argument
 * Return: number of characters
 */
int print_Hexadecimal(unsigned int n)
{
	int len = 0, i = 0, j;
	unsigned int Hex_n = n;
	int *Hex;

	while ((n / 16) != 0)
	{
		n /= 16;
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
		Hex[i] = Hex_n % 16;
		Hex_n /= 16;
		i++;
	}
	for (j = len - 1; j >= 0; j--)
	{
		if (Hex[j] > 9)
		{
			Hex[j] += 7;
		}
		_putchar(Hex[j] + '0');
	}
	free(Hex);

	return (len);
}
/**
 * print_Str - prints pointer values
 * @a: unnamed arguments
 * Return: number of characters printed
 */
int print_Str(va_list a)
{
	int count = 0, i, num;
	char *Str;

	Str = va_arg(a, char *);
	if (Str == NULL)
		Str = "(null)";
	for (i = 0; Str[i] != '\0'; i++)
	{
		if (Str[i] < 32 || Str[i] >= 127)
		{
			_putchar('\\');
			count += 1;
			_putchar('x');
			count += 1;
			num = Str[i];
			if (num < 16)
			{
				_putchar('0');
				count += 1;
			}
			count += print_Hexadecimal(num);
		}
		else
		{
			_putchar(Str[i]);
			count += 1;
		}
	}
	return (count);

}
