#include "main.h"

/**
 * _printf - prints output from format specifiers
 * @format: specifier
 * @...: unnamed arguments
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	int result;
	va_list arguments;

	s_printf f_arr[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"b", print_bin},
		{"u", print_unsigned},
		{"o", print_octal},
		{"d", print_int},
		{"i", print_int},
		{"x", print_hex},
		{"X", print_Hex},
		{"p", print_address},
		{"S", print_Str},
		{"R", print_rot13},
		{"r", print_reversed},
		{NULL, NULL}
	};

	if (format == NULL)
	{
		return (-1);
	}

	va_start(arguments, format);

	result = select_func(format, f_arr, arguments);

	va_end(arguments);
	return (result);
}
