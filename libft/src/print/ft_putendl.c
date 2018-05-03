#include "libft.h"

/*
** Affiche la chaîne de caractères sur la sortie standard suivi d'un retour
** à la ligne.
*/

int	ft_putendl(char const *s)
{
	if (s)
		return (ft_putstr(s) + ft_putchar('\n'));
	return (0);
}
