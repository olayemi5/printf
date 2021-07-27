#include "holberton.h"

/**
 * print_char - prints a character
 * @args: the object to be printed
 *
 * Return: 1 on Success, else -1
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - print a string
 * @args: the object to be printed
 *
 * Return: the length of the string, excluding null character
 */
int print_string(va_list args)
{
	int count = 0;
	char *s = va_arg(args, char *);

	if (!s)
		s = "(null)";

	while (*s)
		count += _putchar(*s++);
	return (count);
}

/**
 * print_int - prints an integer or decimal(base 10)
 * @args: the object to be printed.
 *
 * Return: the length of the int argument provided by args
 */
int print_int(va_list args)
{
	int num, *count;

	count = malloc(sizeof(*count));

	if (!count)
		return (-1);

	*count = 0;
	num = va_arg(args, int);
	*count = _print_int(num, count);

	return (*count);
}

/**
 * _print_int - prints digits recursively
 * @n: the int argument whose digits are to be printed
 * @count: pointer to int digits counter
 *
 * Return: count
 */
int _print_int(int n, int *count)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			*count += _putchar('-');
			n++;
			n = -n;
			if (n / 10)
				_print_int(n / 10, count);
			*count += _putchar((n % 10) + 1 + '0');
			return (*count);
		}

		*count += _putchar('-');
		n = -n;
	}

	if (n / 10)
		_print_int(n / 10, count);
	*count += _putchar((n % 10) + '0');

	return (*count);
}
