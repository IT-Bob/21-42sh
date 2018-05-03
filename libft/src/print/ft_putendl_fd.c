#include "libft.h"

/*
** Affiche la chaîne de caractères sur le fd indiqué suivi d'un retourne
** à la ligne.
*/

int	ft_putendl_fd(char const *s, int fd)
{
	if (s)
		return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
	return (0);
}
