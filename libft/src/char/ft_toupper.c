/*
** ft_toupper() renvoie la lettre qui lui est donnée en paramètre, convertie
** en majuscule.
*/

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
