#include "libft.h"

/*
** ft_memccpy() copie la mémoire de src dans dst jusqu'au caractère c.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		dst1[i] = src1[i];
		if (dst1[i] == (unsigned char)c)
			return (&dst1[i + 1]);
		i++;
	}
	return (NULL);
}
