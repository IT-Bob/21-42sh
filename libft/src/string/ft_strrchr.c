#include "libft.h"

/*
** ft_strrchr() renvoie le pointeur de la dernière occurence du caractère c
** trouvé dans la chaîne s.
** Si c n'est pas trouvé dans s, NULL est renvoyé.
*/

char	*ft_strrchr(const char *s, int c)
{
	char *s1;

	s1 = NULL;
	while (*s)
	{
		if (*s == c)
			s1 = (char*)s;
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else if (s1)
		return (s1);
	return (NULL);
}
