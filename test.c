#ifdef DEBUG
#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int expected, actual;

	expected = printf("This is just a test.\n");
	actual = _printf("This is just a test.\n");
	printf("expected: %d, actual: %d\n\n", expected, actual);

	expected = printf("This is just %c test.\n", 'a');
	actual = _printf("This is just %c test.\n", 'a');
	printf("expected: %d, actual: %d\n\n", expected, actual);

	expected = printf("This is %s a test.\n", "just");
	actual = _printf("This is %s a test.\n", "just");
	printf("expected: %d, actual: %d\n\n", expected, actual);

	expected = printf("This is %s %c test.\n", "just", 'a');
	actual = _printf("This is %s %c test.\n", "just", 'a');
	printf("expected: %d, actual: %d\n\n", expected, actual);

	return (0);
}

#endif
