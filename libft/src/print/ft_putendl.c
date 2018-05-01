/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:20:06 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:22:55 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la chaîne de caractères sur la sortie standard suivi d'un retour
** à la ligne.
*/

int	ft_putendl(char const *s)
{
	if (s)
		return (ft_putstr(s) + ft_putchar('\n'));
	return (0);
}
