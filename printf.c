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
	va_list arg_list;
	int printed;

	va_start(arg_list, format);
	printed = _vprintf(format, arg_list);
	va_end(arg_list);
	return (printed);
}


/**
 * _vprintf - An implementation of the stdio.h printf function
 * @format: The formatted string to print
 * @arg_list: the list of arguments to print
 *
 * Return: The number of characters printed
 */
int _vprintf(const char *format, va_list arg_list)
{
	int i, printed;

	printed = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				_putchar(va_arg(arg_list, int));
				printed++;
				break;
			case 's':
				printed += print_string(va_arg(arg_list, char *));
				break;
			case 'd':
			case 'i':
				printed += print_number(va_arg(arg_list, int), 10);
				break;
			case 'b':
				printed += print_number(va_arg(arg_list, int), 2);
				break;
			case 'r':
				printed += print_reverse(va_arg(arg_list, char *));
				break;
			default:
				_putchar('%');
				printed++;
				break;
			}
		}
		else
		{
			_putchar(format[i]);
			printed++;
		}
	}
	return (printed);
}
