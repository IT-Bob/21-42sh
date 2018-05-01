/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:05:31 by aguerin           #+#    #+#             */
/*   Updated: 2018/03/31 15:05:45 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_isspace.c
**	\author	Alexis Guérin
**	\date	2 février 2018
*/

/*
**	\brief	Test si caractère blanc
**
**	La fonction renvoie **1** si le caractère envoyé est un caractère blanc.
**
**	\param	c	- caractère
**
**	\return	**1** si `c` est un caractère blanc ou **0** sinon
*/

int	ag_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') ||
		(c == '\f') || (c == '\r') || (c == ' '))
		return (1);
	return (0);
}
