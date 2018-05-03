#include "libmt.h"

int		ft_strlenint(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
