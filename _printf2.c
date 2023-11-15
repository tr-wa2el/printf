#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Outputs a formatted string to stdout.
 * @format: The format string.
 * @...: The variable arguments to format.
 * Return: The number of characters output.
 */
int _printf(const char *format, ...)
{
	if (!format)
		return (-1);

	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
	if (*format == '%' && *(format + 1))
	{
	format++;
	switch (*format)
	{
	case 'c':
	count += _putchar(va_arg(args, int));
	break;
	case 's':
	count += _print_str(va_arg(args, const char *));
	break;
	case '%':
	count += _putchar('%');
	break;
	default:
	count += _putchar('%') + _putchar(*format);
	break;
	}
	}
	else
		count += _putchar(*format);
	format++;
	}
	va_end(args);
	return (count);
}


/**
 * _print_str - Writes a string to stdout.
 * @str: The string to be written.
 * Return: The number of characters written.
 */
int _print_str(const char *str)
{
	if (!str)
		str = "(null)";
	int count = 0;

	while (*str)
	{
	count += _putchar(*str);
	str++;
	}
	return (count);
}
