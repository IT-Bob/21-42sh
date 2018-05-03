#include "libft.h"

/*
** ft_isalnum() renvoie 1
** si le caractère donné en paramètre est un chiffre ou une lettre.
*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
