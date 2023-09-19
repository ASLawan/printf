#include "main.h"
#define UNUSED(x) (void)(x)

/**
 * print_us_chars - function that Prints a c
 * @types: Arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_us_chars(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char q = va_arg(types, int);

	return (to_handle_write_char(q, buffer, flags, width, precision, size));
}

/**
 * print_us_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_us_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int length = 0, q;
	char *qwr = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (qwr == NULL)
	{
		qwr = "(null)";

		if (precision >= 6)
			qwr = "      ";
	}
	while (qwr[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &qwr[0], length);
			for (q = width - length; q > 0; q--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (q = width - length; q > 0; q--)
				write(1, " ", 1);
			write(1, &qwr[0], length);
			return (width);
		}
	}
	return (write(1, qwr, length));
}

/**
 * print_us_percent - function that Prints percent sign
 * @types: Arguments list
 * @buffer: Buffer arrys
 * @flags: Active flags
 * @width: The width.
 * @precision: Specification precision
 * @size: Specifier size
 * Return: Printed characters
 */

int print_us_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_us_int - function that Print integer
 * @types: Arguments list
 * @buffer: Print handle by buffer array
 * @flags: Active flags
 * @width: The width.
 * @precision: Specification precision
 * @size: Specifier size
 * Return: Printed character
*/

int print_us_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	int is_negative = 0;
	long int w = va_arg(types, long int);
	unsigned long int nbr;

	w = convert_us_size_number(w, size);
	if (w == 0)
		buffer[q--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	nbr = (unsigned long int)w;
	if (w < 0)
	{
		nbr = (unsigned long int)((-1) * w);
		is_negative = 1;
	}
	while (nbr > 0)
	{
		buffer[q--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	q++;
	return (write_us_number(is_negative, q, buffer, flags,
				width, precision, size));
}

/**
 * print_us_binary - function that Prints unsigned nbr
 * @types: Lista of arguments
 * @buffer: Print handle by buffer array
 * @flags: Active flags
 * @width: The width.
 * @precision: Specification precision
 * @size: Specifier size
 * Return: Printed characters
 */

int print_us_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int q, w, b, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	q = va_arg(types, unsigned int);
	w = 2147483648; /* (2 ^ 31) */
	a[0] = q / w;
	for (b = 1; b < 32; b++)
	{
		w /= 2;
		a[b] = (q / w) % 2;
	}
	for (b = 0, sum = 0, count = 0; b < 32; b++)
	{
		sum += a[b];
		if (sum || b == 31)
		{
			char z = '0' + a[b];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
