#include "../main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * test - test main function
 * @format: a string to test printf
 */
 	 
void test(const char *format, ...)
{
	int expected , actual;
	va_list args_list;
	
	va_start(args_list, format);
	expected = printf(format, args_list);
	putchar('\n');
	actual = _printf(format, args_list);
	putchar('\n');
	printf("expected: %d, actual: %d\n\n", expected, actual);
	va_end(args_list);

}



/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	test("this is just a test");
	test("this is just %c test", 'a');
	test("this is just %s test", "boy");
	test("this is just %c %s test", 'a', "boy");


	return (0);
}

