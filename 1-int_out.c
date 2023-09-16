#include "main.h"

/**
 * print_integer - function that Prints int.
 * @a: The va_list containing int.
 * Return: The number of characters printed.
 */

int print_integer(va_list a)
{
    int num = va_arg(a, int);
    int len = 0;

    /* Print the integer */
    len += printf("%d", num);

    return (len);
}
