/*
** ft_tolower() renvoie la lettre qui lui est donnée en paramètre, convertie
** en minuscule.
*/

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
