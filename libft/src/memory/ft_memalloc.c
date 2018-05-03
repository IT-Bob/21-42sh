#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** ft_memalloc() alloue la mémoire et remplie la zone allouée avec des 0.
*/

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void*)malloc(size);
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}
