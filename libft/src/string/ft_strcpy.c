#include "libft.h"

/*
** ft_strcpy() effectue la copie de 'src' dans 'dst'. Si 'src' est plus grand
** que 'dst', la copie s'arrête. La chaîne est terminée par un '\0'.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
