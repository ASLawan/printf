#include "main.h"

/**
 * select_func - selects appropriate function
 * @f: specifier
 * @f_arr: array of functions
 * @a: unnamed arguments
 * Return: function
 */
int select_func(const char *f, s_printf f_arr[], va_list a)
{
	int i, j, res, num_c = 0;

	for (i = 0; f[i] != '\0'; i++)
	{
		if (f[i] == '%')
		{
			for (j = 0; f_arr[j].spe != NULL; j++)
			{
				if (f[i + 1] == f_arr[j].spe[0])
				{
					res = f_arr[j].func(a);
					if (res == -1)
					{
						return (-1);
					}
					num_c += res;
					break;
				}
			}
			if (f_arr[j].spe == NULL && f[i + 1] != ' ')
			{
				if (f[i + 1] != '\0')
				{
					_putchar(f[i]);
					_putchar(f[i + 1]);
					num_c += 2;
				}
				else
				{
					return (-1);
				}
			}
			i++;
		}
		else
		{
			_putchar(f[i]);
			num_c++;
		}
	}
	return (num_c);
}
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
		{"o", print_octal};
		{"d", print_int},
		{"i", print_int},
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
