#include "main.h"

/**
 * print_string - Prints a string to the stdout
 * @string: A pointer to the string
 *
 * Return: The number of characters printed
 */
int print_string(const char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
	_putchar(string[i]);
	}
	return (i);
}
