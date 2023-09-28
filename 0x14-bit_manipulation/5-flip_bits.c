#include "main.h"

/**
 * flip_bits -  a function that returns the number of bits to flip
 * @n: The first unsigned long integer
 * @m: The second unsigned long integer
 * Return: the number of bits flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bit_mask = n ^ m;
	unsigned int result = 0;

	while (bit_mask)
	{
		if (bit_mask & 1ul)
			result++;
		bit_mask = bit_mask >> 1;
	}
	return (result);
}
