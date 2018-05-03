#include "libft.h"

/*
** ft_lstiter() applique la fonction f sur chaque maillon de la list lst.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*lst1;

	lst1 = lst;
	while (lst1)
	{
		f(lst1);
		lst1 = lst1->next;
	}
}
