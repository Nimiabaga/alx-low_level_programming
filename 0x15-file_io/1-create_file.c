#include "main.h"
/**
 * _strlen - returns lenght of a string
 * @s: the string to check
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

#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename:  is the name of the file to create
 * @text_content: NULL terminated string to write to the file
 * Return: Returns: 1 on success, -1 on failure
 * (file can not be created, file can not be written, write
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_read = 0, len = _strlen(text_content);

	if (filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);
	if (len)
		bytes_read = write(fd, text_content, len);
	close(fd);
	return (bytes_read == len ? 1 : -1);
}
