#include "main.h"

void print_us_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);

/**
 * _printf - Function that performs Printf function
 * @format: The format.
 * Return: The chars Printed
*/

int _printf(const char *format, ...)
{
	int q, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (q = 0; format && format[q] != '\0'; q++)
	{
		if (format[q] != '%')
		{
			buffer[buff_ind++] = format[q];
			if (buff_ind == BUFF_SIZE)
				print_us_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_us_buffer(buffer, &buff_ind);
			flags = get_us_flags(format, &q);
			width = get_us_width(format, &q, list);
			precision = get_us_precision(format, &q, list);
			size = get_us_size(format, &q);
			++q;
			printed = to_handle_print(format, &q, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_us_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * print_us_buffer - function that Prints contents in buffer
 * @buffer: Array characters
 * @buff_ind: Index to add next characters
 */

void print_us_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
		*buff_ind = 0;
	}
}
