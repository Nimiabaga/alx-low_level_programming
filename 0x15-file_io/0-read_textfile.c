#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads a text file and
 * prints it to the POSIX standard output.
 * @letters: number of bytes to read
 * @filename: filename
 * Return: number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char buffer[READ_BUF_SIZE * 8];
	int fd;
	ssize_t bytes_read;

	if (!filename || !letters)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, &buffer[0], letters);
	bytes_read = write(STDOUT_FILENO, &buffer[0], bytes_read);
	close(fd);
	return (bytes_read);

}
