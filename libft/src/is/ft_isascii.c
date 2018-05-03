/*
** ft_isascii() renvoie 1
** si le caractère donné en paramètre fait partie de la table ASCII.
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
