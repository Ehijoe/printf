#include "main.h"
#include <stdlib.h>

/**
 * create_specifier_list - Creates an array of specifier structs
 *
 * Return: A list of the specifiers accepted by _printf
 */
specifier_t *create_specifier_list(void)
{
	specifier_t *list;
	specifier_t init_list[] = {
		{'c', INT_T, arg_print_char},
		{'s', CHAR_P, arg_print_string},
		{'d', INT_T, arg_print_int},
		{'i', INT_T, arg_print_int},
		{'b', UINT, arg_print_binary},
		{'r', CHAR_P, arg_print_reverse},
		{'u', UINT, arg_print_uint},
		{'o', UINT, arg_print_octal},
		{'x', UINT, arg_print_hex},
		{'X', UINT, arg_print_HEX},
		{0, NONE, NULL}
	};
	int len, i;

	for (len = 1; init_list[len - 1].type != NONE; len++)
		continue;
	len++;
	list = malloc(sizeof(specifier_t) * len);
	for (i = 0; i < len; i++)
	{
		list[i] = init_list[i];
	}

	return (list);
}

/**
 * get_print_func - Get the function to print an argument
 * @specifier: The symbol of the specifier to find
 * @specifier_list: A list of the available specifiers
 *
 * Return: A function for printing according to the specifier
 */
arg_print_func get_print_func(char specifier, specifier_t *specifier_list)
{
	int i;

	for (i = 0; specifier_list[i].type != NONE; i++)
	{
		if (specifier_list[i].symbol == specifier)
		{
			return (specifier_list[i].print_func);
		}
	}
	return (NULL);
}

void get_argument(
	char specifier,
	va_list arg_list,
	specifier_t *specifier_list,
	argument * arg
	)
{
	int i;

	arg->type = NONE;
	for (i = 0; specifier_list[i].type != NONE; i++)
	{
		if (specifier_list[i].symbol == specifier)
		{
			arg->type = specifier_list[i].type;
			break;
		}
	}

	switch (arg->type)
	{
	case INT_T:
		arg->integer = va_arg(arg_list, int);
		break;
	case CHAR_P:
		arg->string = va_arg(arg_list, char *);
		break;
	case UINT:
		arg->uint = va_arg(arg_list, unsigned int);
		break;
	default:
		break;
	}
}
