#include "main.h"
#define UNUSED(x) (void)(x)

/**
 * print_us_unsigned - Prints an unsigned number
 * @types: Arguments list
 * @buffer: Prints handle by buffer array
 * @flags: Active flags
 * @width: The width
 * @precision: Specification precision
 * @size: Specifier size
 * Return: Printed Characters
 */

int print_us_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)

{

	int q = BUFF_SIZE - 2;
	unsigned long int nbr = va_arg(types, unsigned long int);

	nbr = convert_us_size_unsgned(nbr, size);
	if (nbr == 0)
		buffer[q--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (nbr > 0)
	{
		buffer[q--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	q++;
	return (write_us_unsgned(0, q, buffer, flags, width, precision, size));
}

/**
 * print_us_octal - function that Prints an unsigned nbr in octal
 * @types: Arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: The width
 * @precision: Specification precision
 * @size: specifier size
 * Return: Printed Characters
 */

int print_us_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int q = BUFF_SIZE - 2;
	unsigned long int nbr = va_arg(types, unsigned long int);
	unsigned long int init_nbr = nbr;

	UNUSED(width);
	nbr = convert_us_size_unsgned(nbr, size);
	if (nbr == 0)
		buffer[q--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (nbr > 0)
	{
		buffer[q--] = (nbr % 8) + '0';
		nbr /= 8;
	}
	if (flags & F_HASH && init_nbr != 0)
		buffer[q--] = '0';
	q++;
	return (write_us_unsgned(0, q, buffer, flags, width, precision, size));
}

/**
 * print_us_hexadecimal - function that Prints an unsigned hexadecimal
 * @types: Arguments list
 * @buffer: Print handle by buffer array
 * @flags: Active flags
 * @width: The width
 * @precision: Specification precision
 * @size: Specifier size
 * Return: Printed characters
 */

int print_us_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_us_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_us_hexa_upper - Fxn that Prints unsigned nbr in upper hexadecimal
 * @types: Arguments list
 * @buffer: Prints hand by buffer array
 * @flags: Active flags
 * @width:The width
 * @precision: Specification precision
 * @size: Specifier size
 * Return: Printed characters
 */

int print_us_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)

{

	return (print_us_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * print_us_hexa - Function that Prints lower or upper hex
 * @types: Arguments list
 * @map_to: Array values to map nbr
 * @buffer: Prints handle by buffer
 * @flags: Calculates active flags
 * @flag_ch: Active flags chars
 * @width: The width
 * @precision: Specification Precision
 * @size: Specifier size
 * @size: Specification size
 * Return: Number of chars Printed characters
 */

int print_us_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)

{
	int q = BUFF_SIZE - 2;
	unsigned long int nbr = va_arg(types, unsigned long int);
	unsigned long int init_nbr = nbr;

	UNUSED(width);
	nbr = convert_us_size_unsgned(nbr, size);
	if (nbr == 0)
		buffer[q--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (nbr > 0)
	{
		buffer[q--] = map_to[nbr % 16];
		nbr /= 16;
	}
	if (flags & F_HASH && init_nbr != 0)
	{
		buffer[q--] = flag_ch;
		buffer[q--] = '0';
	}
	q++;
	return (write_us_unsgned(0, q, buffer, flags, width, precision, size));
}
