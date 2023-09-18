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
					return (-1);
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
