#include "libmt.h"

char	*ft_strjoinfree(char *s1, char *s2, int mode)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (mode == 1 && s1)
		ft_strdel(&s1);
	else if (mode == 2 && s2)
		ft_strdel(&s2);
	else if (mode != 1 && mode != 2 && s1 && s2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (tmp);
}
