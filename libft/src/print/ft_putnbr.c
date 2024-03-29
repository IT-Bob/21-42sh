#include "libft.h"

/*
** Affiche le nombre 'n' sur la sortie standard et retourne le nombre
** de caractères affichés.
*/

int	ft_putnbr(int n)
{
	unsigned int	m;
	int				cmp;

	cmp = 0;
	if (n < 0)
	{
		cmp += ft_putchar('-');
		m = -n;
	}
	else
		m = n;
	if (m > 9)
	{
		cmp += ft_putnbr(m / 10);
		cmp += ft_putchar((m % 10) + '0');
	}
	else
		cmp += ft_putchar(m + '0');
	return (cmp);
}
