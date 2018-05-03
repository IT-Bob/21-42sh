/*
** ft_strclr() met à 0 tous les caractères de la chaîne s.
*/

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (s)
		while (s[i])
			s[i++] = '\0';
}
