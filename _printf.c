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
        characters_printed += output_character(*s); // Output each character of the string
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
    (*format_pointer)++; // Move to the next character in the format string
    
    switch (**format_pointer) {
        case 'c': {
            char c = (char)va_arg(args, int); // Get the next argument as a character
            characters_printed += output_character(c); // Output the character
            break;
        }
        case 's': {
            const char *s = va_arg(args, const char *); // Get the next argument as a string
            characters_printed += output_string(s); // Output the string
            break;
        }
        case '%':
            characters_printed += output_character('%'); // Output the percent sign
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
 * A printf function that outputs a formatted string to stdout.
 *
 * @param format The format string.
 * @param ... The variable arguments to format.
 * @return The number of characters output.
 */
int _printf(const char *format, ...) {
    int characters_printed = 0;
    va_list args;
    va_start(args, format); // Start processing the variable arguments

    for (const char *format_pointer = format; *format_pointer != '\0'; format_pointer++) {
        if (*format_pointer == '%' && *(format_pointer + 1)) {
            characters_printed += process_format_specifier(&format_pointer, args); // Process the format specifier
        } else {
            characters_printed += output_character(*format_pointer); // Output the character
        }
    }

    va_end(args); // End processing the variable arguments
    return characters_printed;
}
