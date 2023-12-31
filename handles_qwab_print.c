#include "main.h"


/**
 * to_handle_print - Prints an argument based on its type
 * @fmat: Formatted string arguments.
 * @list: arguments list printed.
 * @ind: ind.
 * @buffer: Print handle by buffer
 * @flags: Active flags
 * @width: The width.
 * @precision: Specification precision
 * @size: specifier size
 * Return: 1 or 2;
 */

int to_handle_print(const char *fmat, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int q, unknow_len = 0, printed_chars = -1;
	fmat_t fmat_types[] = {
		{'c', print_us_chars}, {'s', print_us_string},
		{'%', print_us_percent},
		{'i', print_us_int}, {'d', print_us_int}, {'b', print_us_binary},
		{'u', print_us_unsigned}, {'o', print_us_octal},
		{'x', print_us_hexadecimal},
		{'X', print_us_hexa_upper}, {'p', print_us_pointer},
		{'S', print_us_non_printable},
		{'r', print_us_reverse}, {'R', print_us_rot13string}, {'\0', NULL}
	};
	for (q = 0; fmat_types[q].fmat != '\0'; q++)
		if (fmat[*ind] == fmat_types[q].fmat)
			return (fmat_types[q].fxn(list, buffer, flags, width, precision, size));
	if (fmat_types[q].fmat == '\0')
	{
		if (fmat[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmat[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmat[*ind] != ' ' && fmat[*ind] != '%')
				--(*ind);
			if (fmat[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmat[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
