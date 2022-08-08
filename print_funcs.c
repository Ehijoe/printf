#include "main.h"
#include <stdlib.h>

/**
 * print_string - Prints a string to the stdout
 * @string: A pointer to the string
 *
 * Return: The number of characters printed
 */
int print_string(const char *string)
{
	int i;

	if (string == NULL)
	{
		return (print_string("(null)"));
	}
	for (i = 0; string[i] != '\0'; i++)
	{
	_putchar(string[i]);
	}
	return (i);
}

/**
 * print_number - Prints a number to stdout
 * @n: The number to print
 *
 * Description: A function that prints an integer to stdout
 */
int print_number(int n)
{
	unsigned int n1 = n;
	int printed = 0;

	if (n < 0)
	{
		n1 = -n;
		_putchar('-');
		printed++;
	}

	if (n1 / 10)
	{
		printed += print_number(n1 / 10);
	}

	_putchar('0' + (n1 % 10));
	return (printed + 1);
}
