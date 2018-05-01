/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:45:43 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:19:52 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche le nombre 'n' sur le fd indiqué  et retourne le nombre affichés.
*/

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;
	int				cmp;

	cmp = 0;
	if (n < 0)
	{
		cmp += ft_putchar_fd('-', fd);
		m = -n;
	}
	else
		m = n;
	if (m > 9)
	{
		cmp += ft_putnbr_fd(m / 10, fd);
		cmp += ft_putchar_fd((m % 10) + '0', fd);
	}
	else
		cmp += ft_putchar_fd(m + '0', fd);
	return (0);
}
