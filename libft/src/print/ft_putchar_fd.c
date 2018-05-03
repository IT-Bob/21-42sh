#include <unistd.h>

/*
** Affiche un caractère sur le 'fd' indiqué.
*/

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
