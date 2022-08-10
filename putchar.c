#include <unistd.h>
#include "main.h"

/**
 * flush - Flushes a buffer to stdout and resets it
 * @buf: The buffer to flush
 */
void flush(buffer_t *buf)
{
	write(1, buf->buff, (buf->len));
	buf->len = 0;
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @buf: Buffer to temporarily write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, buffer_t *buf)
{
	buf->buff[buf->len] = c;
	buf->len++;
	if (buf->len == 1024)
	{
		flush(buf);
	}
	return (1);
}
