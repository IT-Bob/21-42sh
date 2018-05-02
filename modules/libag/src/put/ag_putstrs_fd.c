/*
**	\file	ag_putstrs_fd.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Écriture d'une chaîne de caractères suivie d'un espace sur un `fd`
*/

#include "libag.h"

/*
**	\brief	Écriture d'une chaîne de caractères suivie d'un espace sur un `fd`
**
**	\param	str	- chaîne de caratères
**	\param	fd	- descripteur de fichier où écrire
**
**	\return **nombre de caractère** écrits sur le `fd`
*/

int	ag_putstrs_fd(char const *str, int fd)
{
	if (str)
		return (ft_putstr_fd(str, fd) + ft_putchar_fd(' ', fd));
	return (0);
}
