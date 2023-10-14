#include "main.h"

/**
 * _puts - Prints a string.
 * @str: Function parameter.
 * Return: Integer.
 */

int putstr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		printchar(str[i]);
	return (i);
}
