#include "main.h"
/**
 * _memcpy - a function that copies memories
 * @dest: memory where copied memory is stored
 * @src: memory to be copied
 * @n: number of bytes
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		dest[i] = src[i];
		n--;

	}
	return (dest);
}
