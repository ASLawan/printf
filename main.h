#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/** FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/** SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct
 * @fmt: The format.
 * @fn: Associated function
 */

struct fmt

{

	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);

};

/**
 * typedef struct fmt fmt_t - Struct defination type
 * @fmt: The formats.
 * @fm__t: The associated function.
 */

typedef struct fmt fmt_t;

	int _printf(const char *format, ...);
	int to_handle_print(const char *fmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);


		int print_us_chars(va_list types, char buffer[],

		int flags, int width, int precision, int size);

		int print_us_string(va_list types, char buffer[],

		int flags, int width, int precision, int size);

		int print_us_percent(va_list types, char buffer[],

		int flags, int width, int precision, int size);



		int print_us_int(va_list types, char buffer[],

		int flags, int width, int precision, int size);

		int print_us_binary(va_list types, char buffer[],

		int flags, int width, int precision, int size);

		int print_us_unsigned(va_list types, char buffer[],

		int flags, int width, int precision, int size);

		int print_us_octal(va_list types, char buffer[],

		int flags, int width, int precision, int size);

		int print_us_hexadecimal(va_list types, char buffer[],

		int flags, int width, int precision, int size);

		int print_us_hexa_upper(va_list types, char buffer[],

		int flags, int width, int precision, int size);


		int print_us_hexa(va_list types, char map_to[],

		char buffer[], int flags, char flag_ch, int width, int precision, int size);


		int print_us_non_printable(va_list types, char buffer[],

		int flags, int width, int precision, int size);


		int print_us_pointer(va_list types, char buffer[],

		int flags, int width, int precision, int size);


		int get_us_flags(const char *format, int *i);

		int get_us_width(const char *format, int *i, va_list list);

		int get_us_precision(const char *format, int *i, va_list list);

		int get_us_size(const char *format, int *i);


		int print_us_reverse(va_list types, char buffer[],

		int flags, int width, int precision, int size);


		int print_us_rot13string(va_list types, char buffer[],

		int flags, int width, int precision, int size);


		int to_handle_write_char(char c, char buffer[],

		int flags, int width, int precision, int size);

		int write_us_number(int is_positive, int ind, char buffer[],

		int flags, int width, int precision, int size);

		int write_us_num(int ind, char bff[], int flags, int width, int precision,

		int length, char padd, char extra_c);

		int write_us_pointer(char buffer[], int ind, int length,

		int width, int flags, char padd, char extra_c, int padd_start);


		int write_us_unsgned(int is_negative, int ind,

		char buffer[],

		int flags, int width, int precision, int size);


		int us_is_printable(char);

		int append_us_hexa_code(char, char[], int);

		int us_is_digit(char);


		long int convert_us_size_number(long int num, int size);

		long int convert_us_size_unsgned(unsigned long int num, int size);


#endif
