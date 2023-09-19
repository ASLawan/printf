#include "main.h"

/**
 * get_us_size - function that  cast argument size
 * @format: Formatted string arguments
 * @q: arguments list printed.
 * Return: Precision return
 */

int get_us_size(const char *format, int *q)
{

	int qwab_q = *q + 1;
	int size = 0;

	if (format[qwab_q] == 'l')
		size = S_LONG;
	else if (format[qwab_q] == 'h')
		size = S_SHORT;
	if (size == 0)
		*q = qwab_q - 1;
	else
		*q = qwab_q;
	return (size);
}
