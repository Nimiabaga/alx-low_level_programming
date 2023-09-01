#include "main.h"
/**
 * _strcat - concertenate two strings
 *
 * @dest: the destination string
 * @src: the source string
 *
 * Return: destination string (char *ptr)
 */
char *_strcat(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	b = 0;
	while (src[b] != '\0')
	{

		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}
