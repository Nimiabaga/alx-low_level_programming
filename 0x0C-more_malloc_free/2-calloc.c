#include "main.h"
#include <stdlib.h>
/**
 * _calloc - allocate memory for an array
 *
 * @nmemb: no of bloc of memory
 * @size: size of the element (int)
 *
 * Return: void pointer
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *j;
	size_t i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	j = malloc(nmemb * size);
	if (j == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		j[i] = 0;
	return (j);
}
