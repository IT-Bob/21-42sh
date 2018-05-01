/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:16:02 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:04:14 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Affiche un caractère sur le 'fd' indiqué.
*/

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
