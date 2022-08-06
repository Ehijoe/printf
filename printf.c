#include "main.h"
#include <stdarg.h>

/**
 * _printf - An implementation of the stdio.h printf function
 * @format: The formatted string to print
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed;
	va_list arg_list;

	printed = 0;
	va_start(arg_list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
	if (format[i] == '%')
	{
		i++;
		/* Handle Arguments */
		switch (format[i])
		{
		case '%':
			_putchar('%');
			printed++;
			break;
		case 'c':
			_putchar(va_arg(arg_list, int));
			printed++;
			break;
		case 's':
			printed += print_string(va_arg(arg_list, char *));
			break;
		}
	}
	else
	{
		_putchar(format[i]);
		printed++;
	}
	}
	va_end(arg_list);
	return (printed);
}
