#include "main.h"
/**
 * get_endianness - a function that checks the endianness.
 * Return: Returns: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int k = 1;

	char *byte_ptr = (char *)&k;

	return ((*byte_ptr == 1) ? 1 : 0);

}
