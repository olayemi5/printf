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
