#include "main.h"
#include <stdlib.h>

/**
 * print_string - Prints a string to the stdout
 * @string: A pointer to the string
 * @buf: Buffer to print to
 *
 * Return: The number of characters printed
 */
int print_string(const char *string, buffer_t *buf)
{
	int i;

	if (string == NULL)
	{
		return (print_string("(null)", buf));
	}
	for (i = 0; string[i] != '\0'; i++)
	{
		_putchar(string[i], buf);
	}
	return (i);
}

/**
 * print_number - Prints a number to stdout
 * @n: The number to print
 * @base: the base number to print
 * @buf: Buffer to print to
 *
 * Return: it returns number of characters printed
 */
int print_number(int n, int base, buffer_t *buf)
{
	unsigned int n1 = n;
	int printed = 0;

	if (n < 0)
	{
		n1 = -n;
		_putchar('-', buf);
		printed++;
	}

	if (n1 / base)
	{
		printed += print_number(n1 / base, base, buf);
	}

	_putchar('0' + (n1 % base), buf);
	return (printed + 1);
}

/**
 * print_uint - Print an unsigned integer to a particular base
 * @n: The number to print
 * @base: The base to print the number to
 * @extra_dig_start: The digit after 9 if base > 10
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int print_uint(
	unsigned int n,
	unsigned int base,
	char extra_dig_start,
	buffer_t *buf
	)
{
	int printed = 0;

	if (n / base)
	{
		printed += print_uint(n / base, base, extra_dig_start, buf);
	}

	if ((n % base) > 9)
	{
		_putchar(extra_dig_start + (n % base) - 10, buf);
	}
	else
	{
		_putchar('0' + (n % base), buf);
	}
	return (printed + 1);
}

/**
 * print_reverse - Prints a string in reverse
 * @string: A pointer to the string
 * @buf: The buffer to print to
 *
 * Return: The number of characters printed
 */
int print_reverse(const char *string, buffer_t *buf)
{
	int len;
	int printed;

	if (string == NULL)
	{
		return (print_string("(null)", buf));
	}
	for (len = 0; string[len] != '\0'; len++)
		continue;
	printed = len;
	len--;
	while (len >= 0)
	{
		_putchar(string[len], buf);
		len--;
	}

	return (printed);
}
