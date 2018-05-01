/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:36:41 by aguerin           #+#    #+#             */
/*   Updated: 2017/10/25 09:20:12 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
