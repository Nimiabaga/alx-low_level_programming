#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - a function that converts a binary number to an unsigned int
 * @b:   is pointing to a string of 0 and 1 chars
 * Return: The converted number, or 0 if invalid characters are present
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i] == '0' || b[i] == '1')
	{
		result <<= 1;
		result += b[i] - '0';
		i++;
	}
	return (result);
}
