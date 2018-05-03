#include "libft.h"

/*
** ft_strlen() renvoie le nombre de caractères de 'str'.
*/

unsigned long	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
