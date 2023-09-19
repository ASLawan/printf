#include "main.h"

/**
 * us_is_printable - Evaluates printable char
 * @c: evaluated character
 * Return: 1 if c print, 0 otherwise
 */

int us_is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * append_us_hexa_code - Append ascii in hex to buffer
 * @buffer: char array
 * @q: start Index
 * @ascii_code: ASCII code
 * Return: Always 3
 */

int append_us_hexa_code(char ascii_code, char buffer[], int q)
{

	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[q++] = '\\';
	buffer[q++] = 'x';
	buffer[q++] = map_to[ascii_code / 16];
	buffer[q] = map_to[ascii_code % 16];
	return (3);
}

/**
 * us_is_digit - Verifies char digit or not
 * @c: evaluated char
 * Return: 1 if digit, 0 otherwise
 */

int us_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_us_size_number - Casts number to specified size
 * @nbr: casted number
 * @size: indicating number to cast
 * Return: Casted value
 */

long int convert_us_size_number(long int nbr, int size)
{

	if (size == S_LONG)
		return (nbr);
	else if (size == S_SHORT)
		return ((short)nbr);
	return ((int)nbr);
}
/**
 * convert_us_size_unsgned - Casts number to specified size
 * @nbr: casted number
 * @size: indicating number to casted
 * Return: Casted value
 */

long int convert_us_size_unsgned(unsigned long int nbr, int size)
{
	if (size == S_LONG)
		return (nbr);
	else if (size == S_SHORT)
		return ((unsigned short)nbr);
	return ((unsigned int)nbr);
}
