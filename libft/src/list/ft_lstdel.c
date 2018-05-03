#include "libft.h"
#include <stdlib.h>

/*
** ft_lstdel() supprime la liste alst et libère la mémoire en faisant appel à
** la fonction del sur chaque maillon.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(&(*alst), del);
	}
}
