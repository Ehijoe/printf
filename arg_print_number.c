#include "main.h"

/**
 * arg_print_int - Print an integer argument
 * @arg: Argument to print
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int arg_print_int(argument arg, buffer_t *buf)
{
	return (print_number(arg.integer, 10, buf));
}

/**
 * arg_print_binary - Print an unsigned integer argument as binary
 * @arg: Argument to print
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int arg_print_binary(argument arg, buffer_t *buf)
{
	return (print_uint(arg.uint, 2, '0', buf));
}
