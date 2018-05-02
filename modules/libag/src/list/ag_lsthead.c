/*
**	\file	ag_lsthead.c
**	\author	Alexis Guérin
**	\date	8 mars 2018
*/

#include "libag.h"

/*
**	\brief	Renvoie la tête de liste
**
**	La fonction parcourt la liste et renvoie le premier maillon.
**
**	\param	list	- liste
**
**	\return	pointeur sur la **tête de la liste** ou **NULL** en cas d'erreur
*/

t_lstag	*ag_lsthead(t_lstag *list)
{
	while (list && list->prev)
		list = list->prev;
	return (list);
}
