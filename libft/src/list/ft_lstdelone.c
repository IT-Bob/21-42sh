#include "libft.h"
#include <string.h>
#include <stdlib.h>

/*
** ft_lstdelone() supprime et libère la mémoire d'un maillon en faisant appel
** à la fonction del.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
