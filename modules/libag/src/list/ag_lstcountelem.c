/*
**	\file	ag_lstcountelem.c
**	\author	Alexis Guérin
**	\date	31 janvier 2018
*/

#include "libag.h"

/*
**	\brief	Compte le nombre de maillon de la liste
**
**	La fonction parcourt la liste et renvoie son nombre de maillon.
**
**	\param	list	- liste
**
**	\return	**nombre de maillon**
*/

int	ag_lstcountelem(t_lstag *list)
{
	int	nb;

	nb = 0;
	while (list)
	{
		nb++;
		list = list->next;
	}
	return (nb);
}
