#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b1;

	b1 = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b1[i] = c;
		i++;
	}
	return (b1);
}
