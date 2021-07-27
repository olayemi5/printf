#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct fprinter - a struct holding the
 * format specifier and a pointer to the handling
 * function
 * @spec: the format specifier
 * @hf: a pointer to the handling function
 */
typedef struct fprinter
{
	char *spec;
	int (*hf)(va_list);
} fprinter;

int _printf(const char *format, ...);
int _vprintf(const char *format, va_list args);
int func_call(char, va_list);
int _putchar(char c);

int print_char(va_list);
int print_string(va_list);
int print_int(va_list);
int _print_int(int, int *);

#endif
