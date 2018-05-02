/*
**	\file	fill_tab.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Remplissage de tableau
*/

/*
**	\brief	Remplissage d'un tableau d'entier
**
**	\param	tab		- tableau d'entier à remplir
**	\param	size	- longueur du tableau
**	\param	value	- entier à mettre dans chaque case
*/

void	fill_tab(int tab[], unsigned int size, int value)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		tab[i++] = value;
}
