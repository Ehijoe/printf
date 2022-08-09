#include "main.h"

/**
 * arg_print_char - Print a char argument
 * @arg: Argument to print
 *
 * Return: The number of characters printed
 */
int arg_print_char(argument arg)
{
	_putchar(arg.integer);
	return (1);
}

/**
 * arg_print_string - Print a string argument
 * @arg: Argument to print
 *
 * Return: The number of characters printed
 */
int arg_print_string(argument arg)
{
	return (print_string(arg.string));
}

/**
 * arg_print_reverse - Print a string argument in reverse
 * @arg: Argument to print
 *
 * Return: The number of characters printed
 */
int arg_print_reverse(argument arg)
{
	return (print_reverse(arg.string));
}
