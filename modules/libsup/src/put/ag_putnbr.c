/*
**	\file	ag_putnbr.c
**	\author	Alexis Guérin
**	\date	2 février 2018
**
**	\brief	Affichage de nombre sur la sortie standard
*/

#include "libag.h"

/*
**	\brief	Affichage d'un nombre suivi d'un retour à la ligne
**
**	Écrit le nombre `n` suivi d'un retour à la ligne sur la sortie standard.
**
**	\param	n	- nombre
**
**	\return	**nombre de caractères affichés**
*/

int	ag_putnbrl(int n)
{
	return (ft_putnbr(n) + ft_putchar('\n'));
}

/*
**	\brief	Affichage d'un nombre suivi d'un espace
**
**	Écrit le nombre `n` suivi d'un espace sur la sortie standard.
**
**	\param	n	- nombre
**
**	\return	**nombre de caractères affichés**
*/

int	ag_putnbrs(int n)
{
	return (ft_putnbr(n) + ft_putchar(' '));
}
