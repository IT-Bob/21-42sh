/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:48:25 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:03:50 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Affiche un caractère sur la sortie standard.
*/

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
