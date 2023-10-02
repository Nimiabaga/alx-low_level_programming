#include "main.h"

/**
 * _strlen - this returns the lenght of  a string
 * @s: string to check
 * Return: integer
 */
int _strlen(char *s)
{
	int j = 0;

	if (!s)
		return (0);

	while (*s++)
		j++;
	return (j);
}

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content:  is the NULL terminated string to add at
 * the end of the file
 * Return: 1 on success and 0 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int i;
	ssize_t bytes_read = 0;
	ssize_t len = _strlen(text_content);

	if (!filename)
		return (-1);

	i = open(filename, O_WRONLY | O_APPEND);
	if (i == -1)
		return (-1);

	if (len)
		bytes_read = write(i, text_content, len);
	close(i);
	return (bytes_read == len ? 1 : -1);
}
