#include "main.h"

/**
 * printstr - Prints a string.
 * @str: Pointer to a character.
 * Return: Integer.
 */

int printstr(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		printchar(str[i]);
		count++;
	}
	return (count);
}
