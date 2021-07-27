#include "holberton.h"
#include "func_arr.h"

/**
 * _vprintf - checks a format given and calls a function
 * if format contains specifiers.
 * @format: format string to parse
 * @args: a list of passed arguments
 *
 * Return: the number of character present after format
 * has been parsed.
 */
int _vprintf(const char *format, va_list args)
{
	int count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format++);
			continue;
		}

		switch (*++format)
		{
			case '%':
				count += _putchar(*format);
				break;
			case 'c':
			case 's':
			case 'd':
			case 'i':
				count += func_call(*format, args);
				break;
			default:
				if (!*format)
					return (-1);
				count += _putchar('%');
				count += _putchar(*format);
				break;
		}
		format++;
	}

	return (count);
}

/**
 * func_call - calls for the appropriate function based on the specifier.
 * @c: the format specifier to be checked.
 * @args: the list of passed arguments
 *
 * Return: number of bytes of the passed argument that a format specifier
 * is requesting
 */
int func_call(char c, va_list args)
{
	int i, count = 0;

	for (i = 0; ffuncs[i].spec; i++)
		if (c == ffuncs[i].spec[0])
		{
			count += ffuncs[i].hf(args);
			break;
		}

	return (count);
}
