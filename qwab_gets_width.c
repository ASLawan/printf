#include "main.h"

/**
 * get_us_width - function that Calculates width to print
 * @format: Formatted string arguments.
 * @q: arguments list printed.
 * @list: arguments list
 * Return: width return
 */

int get_us_width(const char *format, int *q, va_list list)
{

	int qwab_q;
	int width = 0;

	for (qwab_q = *q + 1; format[qwab_q] != '\0'; qwab_q++)
	{
		if (us_is_digit(format[qwab_q]))
		{
			width *= 10;
			width += format[qwab_q] - '0';
		}
		else if (format[qwab_q] == '*')
		{
			qwab_q++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*q = qwab_q - 1;
	return (width);
}
