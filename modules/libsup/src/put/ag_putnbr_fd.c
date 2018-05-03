/*
**	\file	ag_putnbr_fd.c
**	\author	Alexis Guérin
**	\date	2 février 2018
**
**	\brief	Écriture d'un nombre sur un `fd`
*/

#include "libag.h"

/*
**	\brief	Écriture d'un nombre sur un `fd` suivi d'un retour à la ligne
**
**	Écrit le nombre `n` suivi d'un retour à la ligne sur le descripteur
**	de fichier `fd`.
**
**	\param	n	- nombre
**	\param	fd	- descripteur de fichier
**
**	\return	**nombre de caractères affichés**
*/

int	ag_putnbrl_fd(int n, int fd)
{
	return (ft_putnbr_fd(n, fd) + ft_putchar_fd('\n', fd));
}

/*
**	\brief	Écriture d'un nombre sur un `fd` suivi d'un espace
**
**	Écrit le nombre `n` suivi d'un espace sur le descripteur de fichier `fd`.
**
**	\param	n	- nombre
**	\param	fd	- descripteur de fichier
**
**	\return	**nombre de caractères affichés**
*/

int	ag_putnbrs_fd(int n, int fd)
{
	return (ft_putnbr_fd(n, fd) + ft_putchar_fd(' ', fd));
}
