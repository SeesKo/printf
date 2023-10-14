#include "main.h"

/**
 * _printf - Processes format string and produces output based on the format.
 * @format: Pointer to a character/format string.
 * Return: Number of characters printed, excluding null-byte at string ends.
 */

int _printf(const char *format, ...)
{
	int i;
	char count_char;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++) /* Iterate through characters */
	{
		if (format[i] != '%') /* Print character if it's not '%' */
		{
			putchar(format[i]);
			count_char++;
		}
		else
		{
			i++; /* Moving past '%' after encountering it */
			switch (format[i])
			{
				case 'c': /* Handling characters */
					putchar(va_arg(args, int));
					count_char++; /* Updating char count */
					break;
				case 's': /* Handling strings */
					printf("%s", va_arg(args, char *));
					count_char++; /* Updating char count */
					break;
				case '%': /* Handling '%' symbol */
					putchar('%');
					count_char++;
					break;
				default: /* Because '%' introduces format specifiers */
					putchar('%');
					putchar(format[i]); /* Char following '%' */
					count_char += 2; /* Add by +2 because '%' and subsequent character */
					break;
			}
		}
	}
	va_end(args);
	return (count_char);
}
