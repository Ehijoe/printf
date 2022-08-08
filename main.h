#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _vprintf(const char *format, va_list arg_list);
int _printf(const char *format, ...);
int print_string(const char *string);
int print_number(int n, int base);
int print_reverse(const char *string);

#endif
