#include "main.h"
#include <stdlib.h>
/**
 * _realloc - reallocate a memory in the heap
 * @ptr: former pointer to the old memory allocated
 * by malloc
 * @old_size: old size allocated by malloc in the heap
 * @new_size: new size allocated by the _realloc function
 * Return: pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *j;
	size_t i, max = new_size;
	char *oldj = ptr;

	if (ptr == NULL)
	{
		j = malloc(new_size);
			return (j);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);

	j = malloc(new_size);
		if (j == NULL)
			return (NULL);
	if (new_size > old_size)
		max = old_size;
	for (i = 0; i < max; i++)
		j[i] = oldj[i];
	free(ptr);
	return (j);
}
