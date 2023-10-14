#include <unistd.h>

/**
 * printchar - writes the character c to stdout.
 * @c: Character to print.
 * Return: 1 on success, -1 on error.
 */

int printchar(char c)
{
	return (write(1, &c, 1));
}
