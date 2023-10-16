#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int printchar(char c);
int _printf(const char *format, ...);
int printstr(char *str);
int print_format(char specifier, va_list args);
int printnum(long num, int base);
int printhex(unsigned int num, char hex_case);
int putaddress(void *ptr);

#endif /* MAIN_H */
