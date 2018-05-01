/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:06:01 by aguerin           #+#    #+#             */
/*   Updated: 2018/03/31 15:06:15 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_lstadd.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Insertion d'un maillon
*/

#include "libag.h"

/*
**	\brief	Insertion d'un maillon en tête
**
**	Insert un maillon en debut de liste.
**
**	\param	alst	- pointeur sur la tête de liste
**	\param	new		- nouveau maillon à insérer
*/

void	ag_lstadd(t_lstag **alst, t_lstag *new)
{
	t_lstag *lst;

	if (alst)
	{
		lst = *alst;
		lst->prev = new;
		new->next = lst;
		*alst = new;
	}
}

/*
**	\brief	Insertion d'un maillon en queue
**
**	Insert un maillon en fin de liste.
**
**	\param	alst	- pointeur sur la tête de liste
**	\param	new		- nouveau maillon à insérer
*/

void	ag_lstaddtail(t_lstag **alst, t_lstag *new)
{
	t_lstag	*tail;

	if (alst)
	{
		tail = ag_lsttail(*alst);
		ag_lstadd(&new, tail);
	}
}
