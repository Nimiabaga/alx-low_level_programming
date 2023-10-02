#include <stdio.h>
#include "main.h"

#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
#define USAGE "Usage: cp file_from file_to\n"

/**
 * main - program
 * @ac: count
 * @av: vector
 * Return: 1 on success
 */
int main(int ac, char **av)
{
	int i_fd = 0;
	int j_fd = 0;
	ssize_t k;
	char buffer[1024];

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	i_fd = open(av[1], O_RDONLY);
	if (i_fd == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);
	j_fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (j_fd == -1)
		dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);

	while ((k = read(i_fd, buffer, 1024)) > 0)
		if (write(j_fd, buffer, k) != k)
			dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);
	if (k == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);
	i_fd = close(i_fd);
	j_fd = close(j_fd);
	if (i_fd)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, i_fd), exit(100);
	if (j_fd)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, i_fd), exit(100);

	return (EXIT_SUCCESS);



}
