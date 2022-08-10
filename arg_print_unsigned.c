#include "main.h"

/**
 * arg_print_uint - Print an unsigned int argument
 * @arg: The argument to print
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int arg_print_uint(argument arg, buffer_t *buf)
{
	return (print_uint(arg.uint, 10, '0', buf));
}

/**
 * arg_print_octal - Print an unsigned int argument in octal
 * @arg: The argument to print
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int arg_print_octal(argument arg, buffer_t *buf)
{
	return (print_uint(arg.uint, 8, '0', buf));
}

/**
 * arg_print_hex - Print an unsigned int argument in hexadecimal
 * @arg: The argument to print
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int arg_print_hex(argument arg, buffer_t *buf)
{
	return (print_uint(arg.uint, 16, 'a', buf));
}

/**
 * arg_print_HEX - Print an unsigned int argument in hex with capital letters
 * @arg: The argument to print
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int arg_print_HEX(argument arg, buffer_t *buf)
{
	return (print_uint(arg.uint, 16, 'A', buf));
}
