# Printf

An implementation of the printf function in the c std library.

## test.c

To test set the DEBUG macro during compilation.

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

The actual printf function

```
Declare printed = 0

Initialize variable args
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
	else:
		_putchar(char)
		printed++
Free variable args

Return printed
```

## print_funcs.c

### function print_string

A function that prints a string as is.

```
Declare printed = 0

For each char in string until '\0':
	_putchar(char)
	printed++

Return printed
```

### print_numbers

a function that prints integers

```
declare a number n



```
