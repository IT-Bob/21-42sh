#include "libft.h"

/*
** ft_bzero() remplie la zone mémoire de s avec 0.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = s;
	i = 0;
	while (i < n)
		s1[i++] = 0;
}
