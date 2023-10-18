#include "main.h"

/**
 * _printf - Processes format string and produces output based on the format.
 * @format: Pointer to a character/format string.
 * Return: Number of characters printed, excluding null-byte at string ends.
 */

int _printf(const char *format, ...)
{
	int i;
	int count_char = 0;
	va_list args;
	char *str;
	void *ptr;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++; /* Move to next character after '%' */
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str != NULL)
					count_char += printstr(str);
				else
					count_char += printstr("(null)");
			}
			else if (format[i] == 'p')
			{
				ptr = va_arg(args, void *);
				if (ptr != NULL)
					count_char += putaddress(ptr);
				else
					count_char += printstr("(null)");
			}
			else
				count_char += print_format(format[i], args);
		}
		else /* Print regular characters */
			count_char += printchar(format[i]);
	}
	va_end(args);
	return (count_char);
}
