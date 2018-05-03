#include "libft.h"

/*
** ft_strcmp() renvoie la différence entre la chaîne 's1' et la chaîne 's2'.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}
