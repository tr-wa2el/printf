#include <stdarg.h>
#include <stdio.h>

/**
 * Outputs a single character to stdout.
 *
 * @param c The character to output.
 * @return The number of characters output (should always be 1).
 */
int output_character(char c) {
    return _putchar(c);
}

/**
 * Outputs a string to stdout.
 *
 * @param s The string to output.
 * @return The number of characters output.
 */
int output_string(const char *s) {
    int characters_printed = 0;
    while (*s) {
        characters_printed += output_character(*s);
        s++;
    }
    return characters_printed;
}

/**
 * Processes a format specifier in a format string.
 *
 * @param format_pointer A pointer to the current position in the format string.
 * @param args The variable argument list.
 * @return The number of characters output as part of processing the format specifier.
 */
int process_format_specifier(const char **format_pointer, va_list args) {
    int characters_printed = 0;
    (*format_pointer)++;
    
    switch (**format_pointer) {
        case 'c': {
            char c = (char)va_arg(args, int);
            characters_printed += output_character(c);
            break;
        }
        case 's': {
            const char *s = va_arg(args, const char *);
            characters_printed += output_string(s);
            break;
        }
        case '%':
            characters_printed += output_character('%');
            break;
        default:
            // Unknown specifier, print it as is
            characters_printed += output_character('%');
            characters_printed += output_character(**format_pointer);
            break;
    }
    return characters_printed;
}

/**
 * A _printf function that outputs a formatted string to stdout.
 *
 * @param format The format string.
 * @param ... The variable arguments to format.
 * @return The number of characters output.
 */
int _printf(const char *format, ...) {
    int characters_printed = 0;
    va_list args;
    va_start(args, format);
at_pointer = format; *format_pointer != '\0'; format_pointer++) {
        if (*format_pointer == '%' && *(format_pointer + 1)) {
            characters_printed += process_format_spec
    for (const char *formifier(&format_pointer, args);
        } else {
            characters_printed += output_character(*format_pointer);
    }

    va_end(args);
    return characters_printed;
}