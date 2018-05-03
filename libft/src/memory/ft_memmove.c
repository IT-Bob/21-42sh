#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;
	int			i;

	dst1 = dst;
	src1 = src;
	if (dst1 < src1)
	{
		i = 0;
		while (i < (int)len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else if (dst1 > src1)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dst1[i] = src1[i];
			i--;
		}
	}
	return (dst);
}
