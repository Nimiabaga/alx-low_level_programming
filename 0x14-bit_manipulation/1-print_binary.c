#include "main.h"
#include <stdio.h>

/**
 * print_binary - a function that prints the binary representation of a number.
 * @n: The number to print in binary
 * Return: 0
 */
void print_binary(unsigned long int n)
{
	int _print_flag = sizeof(n) * 8, prev = 0;

	while (_print_flag)
	{
		if (n & 1L << --_print_flag)
		{
			_putchar('1');
			prev++;

		}
		else if (prev)
			_putchar('0');
	}
	if (!prev)
		_putchar('0');
}
