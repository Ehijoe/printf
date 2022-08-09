#include "../main.h"
#include "test.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

/**
 * test - test main function
 * @format: a string to test printf
 */
void test_vprintf(const char *format, ...)
{
	int expected , actual = 0;
	va_list args_list;

	va_start(args_list, format);
	expected = vprintf(format, args_list);
	putchar('\n');
        va_end(args_list);

	va_start(args_list, format);
	actual = _vprintf(format, args_list);
	putchar('\n');
	va_end(args_list);

	printf("expected: %d, actual: %d\n\n", expected, actual);
}

/**
 * test_mandatory - Tests for the mandatory tasks
 */
void test_mandatory(void)
{
	/* Basic Tests */
	test_vprintf("this is just a test");
	test_vprintf("This format string has too many arguments: %c", 'a', 'b', 'c');
	test_vprintf("This format string has too few arguments: %c %c", 'a');
	test_vprintf("This contains a %% sign.");
	test_vprintf("%z is an invalid specifier");

	/* Tests for the %c and %s specifiers */
	test_vprintf("this is just %c test", 'a');
	test_vprintf("This char is actually an int: %c", (2048 + 'a'));
	test_vprintf("this is just %s test", "boy");
	test_vprintf("this is just %c %s test", 'a', "boy");
	test_vprintf("This is a NULL string: %s", NULL);
	test_vprintf("This is an empty string: %s", "");
	test_vprintf("These are a lot of %c%c%c%cacters.", 'c', 'h', 'a', 'r');

	/* Tests for the %d and %i specifiers */
	test_vprintf("This is a number: %d", 5);
	test_vprintf("This is a negative number: %d", -123551);
	test_vprintf("This is a number: %i", 5);
	test_vprintf("This is a negative number: %i", -123551);
	test_vprintf("This is the maximum int value: %d", INT_MAX);
	test_vprintf("This is the minimum int value: %d", INT_MIN);
}

/**
 * test_advanced - Tests for the advanced tasks
 */
void test_advanced(void)
{
	/* Tests for The unsigned integer formats */
	test_vprintf("This is an unsigned int: %u", 3256);
	test_vprintf("This is the maximum unsigned int: %u", UINT_MAX);
	test_vprintf("This is an octal int: %o", 21554);
	test_vprintf("This is a hex int: %x", 235134);
	test_vprintf("This is a capital hex int: %X", 235134);
}

/**
 * test_custom_specifiers - Test the custom specifiers not in printf
 */
void test_custom_specifiers(void)
{
	int return_val;

	/* Test for %b specifier */
	printf("10101110010010\n");
	return_val = _printf("%b\n", 0b10101110010010);
	printf("expected: %d, actual: %d\n\n", 15, return_val);

	/* Test for %r specifier */
	printf("asdfghjkl;\n");
	return_val = _printf("%r\n", ";lkjhgfdsa");
	printf("expected: %d, actual: %d\n\n", 11, return_val);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	test_mandatory();
	test_custom_specifiers();
	test_advanced();

	return (0);
}

