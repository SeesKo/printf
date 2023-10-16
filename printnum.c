#include "main.h"

/**
 * printnum - Handle different numeric format specifiers.
 * @num: Integer value that is supposed to be printed.
 * @base: Numeric base in which integer will be printed.
 * Return: Number count of printed characters.
 */

int printnum(long num, int base)
{
	int count_char;
	char *values = "0123456789abcdef";

	if (num < 0)
	{
		printchar('-');
		return (printnum(-num, base) + 1);
	}
	else if (num < base)
		return (printchar(values[num]));
	else
	{
        count_char = printnum(num / base, base);
	return (count_char + printnum(num % base, base));
	}
	count_char = printnum(num / base, base);
	return (count_char + printnum(num % base, base));
}
