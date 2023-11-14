#include <stdarg.h>
#include <stdio.h>

/**
 * A _printf function that outputs a formatted string to stdout.
 *
 * @param format The format string.
 * @param ... The variable arguments to format.
 * @return The number of characters output.
 */
int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1)) {
            format++; // Move to the next character after '%'
            switch (*format) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    _putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    while (*s) {
                        _putchar(*s++);
                        count++;
                    }
                    break;
                }
                case '%':
                   _putchar('%');
                    count++;
                    break;
                default:
                    // Unknown specifier, print it as is
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
