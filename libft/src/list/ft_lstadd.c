#include "libft.h"

/*
** Ajoute un maillon en debut de liste
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *lst;

	lst = *alst;
	lst->prev = new;
	new->next = lst;
	*alst = new;
}
