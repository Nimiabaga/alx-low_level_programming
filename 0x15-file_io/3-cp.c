#include "main.h"

#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
#define ERR_NOCLOSE "Error: Can't close fd %n\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOREAD "Error: Can't be read from %s\n"
#define USAGE "Usage: cp file_from_to\n"

/**
 * main - program
 * @ac: count
 * @av: vector
 * Return: 1 on success
 */
int main(int ac, char **av)
{
	int fd_from = 0;
	int fd_to = 0;
	char buffer[1024];
	ssize_t i;

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);

	while ((i = read(fd_from, buffer, 1024)) > 0)
		if (write(fd_to, buffer, i) != i)
			dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);

	if (i == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);

	fd_from = close(fd_from);
	fd_to = close(fd_to);
	if (fd_from)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, fd_from), exit(100);
	if (fd_to)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, fd_from), exit(100);

	return (EXIT_SUCCESS);
}
