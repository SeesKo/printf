#include "main.h"

/**
 * printchar - Prints a character to the standard output.
 * @c: The character to print.
 * Return: 1 on success.
 */

int printchar(char c)
{
	return (write(1, &c, 1));
}
