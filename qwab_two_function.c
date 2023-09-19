#include "main.h"
#define UNUSED(x) (void)(x)

/**
 * print_us_pointer - Function that Prints value of a pointer
 * @types: Arguments list
 * @buffer: Print handle by buffer array
 * @flags: Active flags
 * @width: The width
 * @precision: Specification precision
 * @size: Specifier size
 * Return: Printed characters
*/

int print_us_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char trakex_q = 0, qwab = ' ';
	int ind = BUFF_SIZE - 2, length = 2, qwab_start = 1;
	unsigned long nbr_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);


	UNUSED(width);
	UNUSED(size);
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	nbr_addrs = (unsigned long)addrs;
	while (nbr_addrs > 0)
	{
		buffer[ind--] = map_to[nbr_addrs % 16];
		nbr_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		qwab = '0';
	if (flags & F_PLUS)
		trakex_q = '+', length++;
	else if (flags & F_SPACE)
		trakex_q = ' ', length++;
	ind++;
	return (write_us_pointer(buffer, ind, length,
				width, flags, qwab, trakex_q, qwab_start));


}

/**
 * print_us_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Arguments list
 * @buffer: Print handle by the Buffer Array
 * @flags: Active flags
 * @width: The width
 * @precision: Specification precision
 * @size: Specifier size
 * Return: Number of chars printed
 */

int print_us_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int q = 0, offset = 0;
	char *qwab = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (qwab == NULL)
		return (write(1, "(null)", 6));
	while (qwab[q] != '\0')
	{
		if (us_is_printable(qwab[q]))

			buffer[q + offset] = qwab[q];
		else
			offset += append_us_hexa_code(qwab[q], buffer, q + offset);
		q++;
	}
	buffer[q + offset] = '\0';
	return (write(1, buffer, q + offset));

}

/**
 * print_us_reverse - function that Prints reverse string.
 * @types: Arguments list
 * @buffer: Print handle by buffer array
 * @flags: Active flags
 * @width: The width
 * @precision: Specification precision
 * @size: Specifier size
 * Return: Printed characters
 */

int print_us_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *qbr;
	int q, count = 0;
	int y;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	qbr = va_arg(types, char *);
	if (qbr == NULL)
	{
		UNUSED(precision);
		qbr = ")Null(";
	}
	for (q = 0; qbr[q]; q++)
		;

	for (y = q - 1; y >= 0; y--)
	{
		char z = qbr[y];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_us_rot13string - function that Print a string in rot13.
 * @types: ArgumentS list
 * @buffer: Print handle by Buffer array
 * @flags: Active flags
 * @width: The width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Printed characters
 */

int print_us_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)

{

	char b;
	char *qbr;
	unsigned int q, w;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	qbr = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (qbr == NULL)
		qbr = "(AHYY)";
	for (q = 0; qbr[q]; q++)
	{
		for (w = 0; in[w]; w++)
		{
			if (in[w] == qbr[q])
			{
				b = out[w];
				write(1, &b, 1);
				count++;
				break;
			}
		}
		if (!in[w])
		{
			b = qbr[q];
			write(1, &b, 1);
			count++;
		}
	}
	return (count);
}
