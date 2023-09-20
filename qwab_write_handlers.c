#include "main.h"

/**
 * to_handle_write_char - function that Prints string
 * @c: type of char
 * @buffer: Buffer array
 * @flags: Active flags.
 * @width: The width.
 * @precision: specifier precision
 * @size: specifier size
 * Return: printed number
 */

int to_handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)

{

	int q = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags & F_ZERO)
		pad = '0';
	buffer[q++] = c;
	buffer[q] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (q = 0; q < width - 1; q++)
			buffer[BUFF_SIZE - q - 2] = pad;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - q - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - q - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_us_number - function that Prints string
 * @is_negative: arguments list
 * @ind: types of char
 * @buffer: print handle by buffer array
 * @flags:  Active flags
 * @width: The width.
 * @precision: specifier precision
 * @size: specifier size
 * Return: printed chars
 */

int write_us_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	return (write_us_num(ind, buffer, flags, width, precision,
				length, pad, extra_ch));
}

/**
 * write_us_num - function that number using bufffer
 * @ind: start index on buffer
 * @buffer: print handle by Buffer
 * @flags: active Flags
 * @width: the width
 * @prec: specifier precision
 * @length: length of number
 * @pad: Padding characters
 * @extra_c: Extra characters
 * Return: printed chars
 */

int write_us_num(int ind, char buffer[],
		int flags, int width, int prec,
		int length, char pad, char extra_c)
{
	int q, pad_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' ';
	if (prec > 0 && prec < length)
		pad = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (q = 1; q < width - length + 1; q++)
			buffer[q] = pad;
		buffer[q] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], q - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], q - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			return (write(1, &buffer[pad_start], q - pad_start) +
					write(1, &buffer[ind], length - (1 - pad_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_us_unsgned - function to Write unsigned nbr
 * @is_negative: negative indicator
 * @ind: starts index
 * @buffer: print handle by buffer array
 * @flags: active Flags
 * @width: the Width
 * @precision: specifier precision
 * @size: specifier size
 * Return: printed chars
 */

int write_us_unsgned(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, q = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		pad = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (width > length)
	{
		for (q = 0; q < width - length; q++)
			buffer[q] = pad;
		buffer[q] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], q));
		}
		else
		{
			return (write(1, &buffer[0], q) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}

/**
 * write_us_pointer - function that Write memory address
 * @buffer: print handle  by buffer array
 * @ind: start index
 * @length: number of length
 * @width: the width
 * @flags: active Flags
 * @pad: padding characters
 * @extra_c: extra character
 * @pad_start: padding start
 * Return: printed chars
 */

int write_us_pointer(char buffer[], int ind, int length,
		int width, int flags, char pad, char extra_c, int pad_start)
{

	int q;

	if (width > length)
	{
		for (q = 3; q < width - length + 3; q++)
			buffer[q] = pad;
		buffer[q] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], q - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], q - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], q - pad_start) +
					write(1, &buffer[ind], length - (1 - pad_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));

}
