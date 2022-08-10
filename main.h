#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>

/**
 * struct buffer - A buffer to store output before printing to sdout
 * @buff: An array of characters to be written
 * @len: The number of characters in the array
 */
struct buffer
{
	char *buff;
	int len;
};

/**
 * buffer_t - A typedef for the buffer struct
 */
typedef struct buffer buffer_t;

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
typedef int (*arg_print_func)(argument, buffer_t *);

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

void flush(buffer_t *buf);
int _putchar(char c, buffer_t *buf);
int _vprintf(const char *format, va_list arg_list);
int _printf(const char *format, ...);
int print_string(const char *string, buffer_t *buf);
int print_number(int n, int base, buffer_t *buf);
int print_uint(unsigned int n,
	       unsigned int base,
	       char extra_dig_start,
	       buffer_t *buf);
int print_reverse(const char *string, buffer_t *buf);
arg_print_func get_print_func(char specifier, specifier_t *specifier_list);
void get_argument(
		  char specifier,
		  va_list arg_list,
		  specifier_t *specifier_list,
		  argument *arg
		  );
specifier_t *create_specifier_list(void);

/* Function prototypes for argument printing functions */
int arg_print_char(argument arg, buffer_t *buf);
int arg_print_string(argument arg, buffer_t *buf);
int arg_print_reverse(argument arg, buffer_t *buf);

int arg_print_int(argument arg, buffer_t *buf);
int arg_print_binary(argument arg, buffer_t *buf);

int arg_print_uint(argument arg, buffer_t *buf);
int arg_print_octal(argument arg, buffer_t *buf);
int arg_print_hex(argument arg, buffer_t *buf);
int arg_print_HEX(argument arg, buffer_t *buf);

#endif
