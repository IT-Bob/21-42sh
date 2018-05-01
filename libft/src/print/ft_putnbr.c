/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:28:13 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:26:56 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche le nombre 'n' sur la sortie standard et retourne le nombre
** de caractères affichés.
*/

int	ft_putnbr(int n)
{
	unsigned int	m;
	int				cmp;

	cmp = 0;
	if (n < 0)
	{
		cmp += ft_putchar('-');
		m = -n;
	}
	else
		m = n;
	if (m > 9)
	{
		cmp += ft_putnbr(m / 10);
		cmp += ft_putchar((m % 10) + '0');
	}
	else
		cmp += ft_putchar(m + '0');
	return (cmp);
}
