/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 10:26:51 by aguerin           #+#    #+#             */
/*   Updated: 2018/04/02 10:27:07 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_putnstr.c
**	\author	Alexis Guérin
**	\date	2 février 2018
**
**	\brief	Affichage d'un nombre limité de caractères
*/

#include "libag.h"

/*
**	\brief	Affichage de `n` caractères d'une chaîne
**
**	ft_putnstr() affiche les `n` premiers caractères de la chaîne `str`.
**	Si `n` est plus grand que la taille de la chaîne, l'affichage s'arrête
**	en fin de chaîne.
**	La fonction renvoie le nombre de caractères affichés.
**
**	\param	str	- chaîne
**	\param	n	- nombre de caractères à afficher
**
**	\return	**nombre de caractères affichés** ou **-1** en cas d'erreur
*/

int	ag_putnstr(const char *str, unsigned int n)
{
	unsigned int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len] && len <= n)
		len++;
	if (n > len)
		n = len;
	return (write(1, str, n));
}

/*
**	\brief	Affichage de `n` caractères d'une chaîne suivi
**			d'un retour à la ligne
**
**	ft_putnstr() affiche les `n` premiers caractères de la chaîne `str` suivi
**	d'un retour à la ligne.
**	Si `n` est plus grand que la taille de la chaîne, l'affichage s'arrête
**	en fin de chaîne.
**	La fonction renvoie le nombre de caractères affichés.
**
**	\param	str	- chaîne
**	\param	n	- nombre de caractères à afficher
**
**	\return	**nombre de caractères affichés** ou **-1** en cas d'erreur
*/

int	ag_putnstrl(const char *str, unsigned int n)
{
	return (ag_putnstr(str, n) + ft_putchar('\n'));
}

/*
**	\brief	Affichage de `n` caractères d'une chaîne suivi d'un espace
**
**	ft_putnstr() affiche les `n` premiers caractères de la chaîne `str` suivi
**	d'un espace.
**	Si `n` est plus grand que la taille de la chaîne, l'affichage s'arrête
**	en fin de chaîne.
**	La fonction renvoie le nombre de caractères affichés.
**
**	\param	str	- chaîne
**	\param	n	- nombre de caractères à afficher
**
**	\return	**nombre de caractères affichés** ou **-1** en cas d'erreur
*/

int	ag_putnstrs(const char *str, unsigned int n)
{
	return (ag_putnstr(str, n) + ft_putchar(' '));
}
