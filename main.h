#ifndef _MAIN_
#define _MAIN_

int _putchar(char);
int output_character(char c);
int output_string(const char *s);
int process_format_specifier(const char **format_pointer, va_list args);
int custom_printf(const char *format, ...);

#endif
