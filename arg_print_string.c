#include "main.h"

/**
 * arg_print_char - Print a char argument
 * @arg: Argument to print
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int arg_print_char(argument arg, buffer_t *buf)
{
	_putchar(arg.integer, buf);
	return (1);
}

/**
 * arg_print_string - Print a string argument
 * @arg: Argument to print
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int arg_print_string(argument arg, buffer_t *buf)
{
	return (print_string(arg.string, buf));
}

/**
 * arg_print_reverse - Print a string argument in reverse
 * @arg: Argument to print
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int arg_print_reverse(argument arg, buffer_t *buf)
{
	return (print_reverse(arg.string, buf));
}
