#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

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
	arg_print_func print;
	specifier_t *specifier_list = create_specifier_list();
	argument arg;
	buffer_t buffer;

	buffer.buff = malloc(1024);
	buffer.len = 0;
	printed = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			print = get_print_func(format[i], specifier_list);
			if (print == NULL)
			{
				_putchar(format[i], &buffer);
				printed++;
			}
			else
			{
				get_argument(format[i],
					     arg_list,
					     specifier_list,
					     &arg
					);
				printed += print(arg, &buffer);
			}
		}
		else
		{
			_putchar(format[i], &buffer);
			printed++;
		}
	}
	flush(&buffer);
	free(specifier_list);
	free(buffer.buff);
	return (printed);
}
