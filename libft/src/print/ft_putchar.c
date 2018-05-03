#include <unistd.h>

/*
** Affiche un caractère sur la sortie standard.
*/

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
