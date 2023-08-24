#include "main.h"

/**
 * _strncat - Concatenates two strings using at most
 *
 * an inputted number of bytes from src.
 * @dest: The string to be append  upon.
 * @src: The string to be append to dest'
 * @n: The number of byes from scr to append to dest
 * Return:  a pointer to the reulting string dest
 */
char *_strncat(char *dest, char *src, int n)

{

	int index = 0, dest_len = 0;

	while (dest[index++])
	dest_len++;
	for (index = 0; src[index] && index < n; index++)
	dest[dest_len++] = src[index];
	return (dest);
}
