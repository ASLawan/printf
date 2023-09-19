#include "main.h"

/**
 * get_us_flags - Active flags
 * @format: Formatted string arguments
 * @q: The parameter.
 * Return: Flags
 */

int get_us_flags(const char *format, int *q)
{

	int w, qwab_q;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (qwab_q = *q + 1; format[qwab_q] != '\0'; qwab_q++)
	{
		for (w = 0; FLAGS_CH[w] != '\0'; w++)
			if (format[qwab_q] == FLAGS_CH[w])
			{
				flags |= FLAGS_ARR[w];
				break;
			}
		if (FLAGS_CH[w] == 0)
			break;
	}
	*q = qwab_q - 1;
	return (flags);
}
