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
	int k = 0;

	if (b == NULL)
		return (0);

	for (k = 0; b[k]; k++)
	{
		if (b[k] < '0' || b[k] > '1')
			return (0);
		result = 2 * result + (b[k] - '0');
	}
	return (result);
}
