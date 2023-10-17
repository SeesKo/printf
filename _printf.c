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

    va_start(args, format);

    /* Looping through characters */
    for (i = 0; format[i] != '\0'; i++)
    {
        /* Check for format specifier */
        if (format[i] == '%')
        {
            i++; /* Move to next character after '%' */

            if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                char *str_copy;
                if (str != NULL)
                {
                    int len = 0;
                    while (str[len])
                        len++;
                    str_copy = malloc(len + 1);
                    if (str_copy != NULL)
                    {
                        int j;
                        for (j = 0; str[j] != '\0'; j++)
                            str_copy[j] = str[j];
                        str_copy[j] = '\0';

                        count_char += printstr(str_copy);
                        free(str_copy);
                    }
                }
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
