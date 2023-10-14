#include "main.h"

/**
 * _printf - Processes format string and produces output based on the format.
 * @format: Pointer to a character/format string.
 * Return: Number of characters printed, excluding null-byte at string ends.
 */

int _printf(const char *format, ...)
{
	int i, count_str, count_char = 0;
	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && format[1] == '\0')) /* Check NULL/Empty */
	{
		return (-1);
	}
	for (i = 0; format[i] != '\0'; i++) /* Iterate through characters */
	{
		if (format[i] != '%')
		{
			printchar(format[i]); /* Print regular char */
		}
		else if (format[i + 1] == 'c')
		{
			printchar(va_arg(args, int)); /* Print char */
			i++;
		}
		else if (format[i + 1] == 's')
		{
			count_str = putstr(va_arg(args, char *)); /* Print string */
			i++;
			count_char += (count_str - 1); /* String minus format specifier */
		}
		else if (format[i + 1] == '%')
			printchar('%'); /* Literally print '%' */
		count_char += 1;
	}
	if (format[i - 1] == '%') /* See if previous char is '%' with no specifier */
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (count_char);
}
