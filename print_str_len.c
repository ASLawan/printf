#include "main.h"

/**
 * str-len - computes string length
 * @s: pointer to string
 * Return: length
 */

int str_len(char *s)
{
	int i, len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		len += 1;
	}
	return (len);
}

/**
 * str_len_const - computes string length
 * for const pointers to string
 * @s: const pointer to string
 * Return: length
 */

int str_len_const(char *s)
{
	int i, len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		len += 1;
	}
	return (len);
}
