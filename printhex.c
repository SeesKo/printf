#include "main.h"

/**
 * printhex - Handle hexadecimal format specifiers (%x and %X).
 * @num: Integer value that is supposed to be printed.
 * @hex_case: Indicates if the formatting should be lowercase
 * ('x') or uppercase ('X').
 * Return: Number count of printed characters.
 */

int printhex(unsigned int num, char hex_case)
{
	int count_char = 0;
	char *values;

	if (hex_case == 'X')
		values = "0123456789ABCDEF";
	else
		values = "0123456789abcdef";

	if (num >= 16)
		count_char += printhex(num / 16, hex_case);

	printchar(values[num % 16]);

	return (count_char + 1);
}
