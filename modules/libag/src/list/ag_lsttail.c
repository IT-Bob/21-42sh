/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_lsttail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:08:27 by aguerin           #+#    #+#             */
/*   Updated: 2018/03/31 15:08:35 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_lsttail.c
**	\author	Alexis Guérin
**	\date	31 janvier 2018
*/

#include "libag.h"

/*
**	\brief	Renvoie la queue de liste
**
**	La fonction parcourt la liste et renvoie le dernier maillon.
**
**	\param	list	- liste
**
**	\return	pointeur sur la **queue de la liste** ou **NULL** en cas d'erreur
*/

t_lstag	*ag_lsttail(t_lstag *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}
