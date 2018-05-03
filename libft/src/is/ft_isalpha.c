/*
** ft_isalpha() renvoie 1
** si le caractère donné en paramètre est une lettre.
*/

int		ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}
