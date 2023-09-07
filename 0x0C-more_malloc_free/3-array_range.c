#include "main.h"
#include <stdlib.h>
/**
 * array_range - create an array of integers
 * @min: minimum value
 * @max: value
 * Return: int pointer to the allocated memory
 */
int *array_range(int min, int max)
{
	int j, p;
	int *a;

	if (min > max)
		return (NULL);
	p = max - min + 1;
	a = malloc(sizeof(int) * p);
	if (a == NULL)
		return (NULL);
	for (j = 0; j < p; j++)
	{
		a[j] = min;
		min++;
	}
	return (a);
}
