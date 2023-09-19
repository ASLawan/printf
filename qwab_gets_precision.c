#include "main.h"

/**
 * get_us_precision - function that Calculates precision
 * @format: Formatted string arguments
 * @q: Arguments list printed
 * @list: Arguments list
 * Return: Precision.
 */

int get_us_precision(const char *format, int *q, va_list list)
{
	int qwab_q = *q + 1;
	int precision = -1;

	if (format[qwab_q] != '.')
		return (precision);
	precision = 0;
	for (qwab_q += 1; format[qwab_q] != '\0'; qwab_q++)
	{
		if (us_is_digit(format[qwab_q]))
		{
			precision *= 10;
			precision += format[qwab_q] - '0';
		}
		else if (format[qwab_q] == '*')
		{
			qwab_q++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*q = qwab_q - 1;
	return (precision);
}
