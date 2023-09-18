#ifndef MAIN_H_HEADER_FILE
#define MAIN_H_HEADER_FILE

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/**
 * struct s_printf - matches specifier to function
 * @spe: specifier
 * @func: function pointer
 * Description: matches format specifiers to functions
 */
typedef struct s_printf
{
	char *spe;
	int (*func)(va_list);
} s_printf;

/*******************function prototypes*****************/

int print_char(va_list a);
int print_percent(va_list);
int print_str(va_list a);
int str_len(char *s);
int str_len_const(char *s);
int _putchar(char c);
int _printf(const char *format, ...);
int print_bin(va_list a);
int print_unsigned(va_list a);
int print_octal(va_list a);
int print_int(va_list a);
int print_hex(va_list a);
int print_Hex(va_list a);
int select_func(const char *f, s_printf f_arr[], va_list a);
int print_address(va_list a);

#endif
