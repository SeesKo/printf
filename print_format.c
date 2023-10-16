#include "main.h"

/**
 * print_format - Formats and prints data based on specifier.
 * @specifier: Passes a format specifier character to the function.
 * @args: Allows function to handle arguments of different types.
 * Return: Number of characters printed.
 */

int print_format(char specifier, va_list args)
{
	int count_char;

	count_char = 0;

	if (specifier == 'c')
		count_char += printchar(va_arg(args, int));
	else if (specifier == 's')
		count_char += printstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count_char += printnum((long)(va_arg(args, int)), 10);
	else if (specifier == 'u')
		count_char += printnum((long)(va_arg(args, unsigned int)), 10);
	else if (specifier == 'o')
		count_char += printnum((long)(va_arg(args, unsigned int)), 8);
	else if (specifier == 'x')
		count_char += printhex((unsigned int)(va_arg(args, unsigned int)), 'x');
	else if (specifier == 'X')
		count_char += printhex((unsigned int)(va_arg(args, unsigned int)), 'X');
	else if (specifier == 'p')
		count_char += putaddress(va_arg(args, void*));
	else if (specifier == '%')
		count_char += printchar('%');
	else
	{
		count_char += printchar('%');
		count_char += printchar(specifier);
	}
	return (count_char);
}
