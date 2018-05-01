/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:43:11 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:23:45 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la chaîne de caractères sur le fd indiqué suivi d'un retourne
** à la ligne.
*/

int	ft_putendl_fd(char const *s, int fd)
{
	if (s)
		return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
	return (0);
}
