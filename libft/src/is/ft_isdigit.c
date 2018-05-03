/*
** ft_isdigit() renvoie 1
** si le caractère donné en paramètre est un chiffre.
*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
