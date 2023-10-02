#include "main.h"
/**
 * _strlen - returns lenght of string
 * @s: string to check
 * Return: integer
 */
int _strlen(char *s)
{
	int k = 0;
	 if (!s)
		 return (0);
	 while (s++)
		 k++;
	 return (k);

}
/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @text_content: NULL terminated string to add at the end of the file
 * @filename: name of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t bytes_read = 0, len = _strlen(text_content);
	int fd;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (len)
		bytes_read = write(fd, text_content, len);
	close(fd);
	return (bytes_read == len ? 1 : -1);


}
