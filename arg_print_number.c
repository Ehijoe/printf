#include "main.h"

/**
 * arg_print_int - Print an integer argument
 * @arg: Argument to print
 *
 * Return: The number of characters printed
 */
int arg_print_int(argument arg)
{
	return (print_number(arg.integer, 10));
}

/**
 * arg_print_binary - Print an unsigned integer argument as binary
 * @arg: Argument to print
 *
 * Return: The number of characters printed
 */
int arg_print_binary(argument arg)
{
	return (print_uint(arg.uint, 2, '0'));
}
