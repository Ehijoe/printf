# Printf

An implementation of the printf function in the c std library.

## test

A directory containing the test program.

Tests are of the form:
```
expected = printf(Test, ...)
actual = _printf(Test, ...)
printf("expected: %d, actual: %d\n\n", expected, actual)
```

## main.h

Prototype for:
- _putchar
- _printf
- print_string

## putchar.c

Identical to Holberton school's _putchar.

## printf.c

### function _printf

The actual printf function.

```
Initialize va_list
Set printed = _vprintf(format, va_list)
Free va_list
return printed
```

### function _vprintf

A function that prints the format string using arguments from a va_list

```
Declare printed = 0

For each character in format until '\0':
	if char == '%':
		switch (next):
			case '%':
				_putchar('%')
				printed++
			case 's':
				printed += print_string(get_arg())
			case 'c':
				_putchar(c)
				printed ++
            case 'd' or 'i':
                printed += print_number(get_arg())
	else:
		_putchar(char)
		printed++

Return printed
```

## print_funcs.c

### function print_string

A function that prints a string and returns the number of characters printed.

```
Declare printed = 0

For each char in string until '\0':
	_putchar(char)
	printed++

Return printed
```

### print_numbers

A function that prints integers and returns the number of characters printed.

```
if n is negative:
    print '-'

if n >= 10:
    print_numbers(n / 10)

_putchar('0' + (n % 10))
```
