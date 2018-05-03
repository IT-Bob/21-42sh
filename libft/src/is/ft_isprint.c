/*
** ft_isprint() renvoie 1
** si le caractère donné en paramètre est un caractère affichable.
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
