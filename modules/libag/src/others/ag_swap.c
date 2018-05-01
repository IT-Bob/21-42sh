/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:15:11 by aguerin           #+#    #+#             */
/*   Updated: 2018/03/31 15:15:42 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_swap.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Échange de pointeur
*/

/*
** \brief	Échange de deux pointeurs sur entiers
**
** \param	a	- premier pointeur
** \param	b	- deuxième pointeur
*/

void	ag_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
