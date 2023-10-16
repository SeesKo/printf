#include "main.h"

/**
 * putaddress - Prints a memory address.
 * @ptr: Pointer to a memory address.
 * Return: Number of characters printed.
 */

int putaddress(void *ptr)
{
	int count_char = 0;

	unsigned long address = (unsigned long)ptr;

	count_char += printstr("0x");
	count_char += printnum(address, 16);

	return (count_char);
}
