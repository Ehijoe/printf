#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>

/**
 * enum arg_type - The data type of the argument
 * @INT_T: An integer
 * @CHAR_P: A pointer to a char
 * @UINT: An unsigned integer
 * @NONE: No argument
 */
typedef enum arg_type
{
	INT_T,
	CHAR_P,
	UINT,
	NONE
} arg_type;

/**
 * struct argument - A struct that stores a variable argument
 * @type: The data type of the argument
 * @integer: The value if it is an integer
 * @string: The value if it is a pointer to a char
 * @uint: The value if it is an unsigned integer
 */
struct argument
{
	arg_type type;
	int integer;
	char *string;
	unsigned int uint;
};

/**
 * argument_t - A typedef for an argument struct
 */
typedef struct argument argument;

/**
 * arg_print_func - A typedef for a function to print an argument
 */
typedef int (*arg_print_func)(argument);

/**
 * struct specifier - A struct that contains info about a format specifier
 * @symbol: The character representing the format
 * @type: The data type passed to the printing function
 * @print_func: The function with which to print
 */
struct specifier
{
	char symbol;
	arg_type type;
	arg_print_func print_func;
};

typedef struct specifier specifier_t;

int _putchar(char c);
int _vprintf(const char *format, va_list arg_list);
int _printf(const char *format, ...);
int print_string(const char *string);
int print_number(int n, int base);
int print_uint(unsigned int n, unsigned int base, char extra_dig_start);
int print_reverse(const char *string);
arg_print_func get_print_func(char specifier, specifier_t *specifier_list);
void get_argument(
		  char specifier,
		  va_list arg_list,
		  specifier_t *specifier_list,
		  argument *arg
		  );
specifier_t *create_specifier_list(void);

/* Function prototypes for argument printing functions */
int arg_print_char(argument arg);
int arg_print_string(argument arg);
int arg_print_reverse(argument arg);

int arg_print_int(argument arg);
int arg_print_binary(argument arg);

int arg_print_uint(argument arg);
int arg_print_octal(argument arg);
int arg_print_hex(argument arg);
int arg_print_HEX(argument arg);

#endif
