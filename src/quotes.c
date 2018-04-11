#include "sh.h"

/*
**	\brief	Détection de quotes ouvertes ou de backslash en fin de ligne
**
**	La fonction regarde dans la ligne si des `quotes` (simples ou doubles ou back)
**	sont ouvertes et non fermées ou si un `backslash` est présent en fin
**	de ligne. Si oui, elle renvoie le **code ASCII du caractère** correspondant,
**	ou **0** sinon.
**
**	La fonction supprime le caractère `\` si celui-ci est le dernier de la chaîne.
**
**	\param	line	- pointeur sur la ligne à regarder
**
**	\return	**0** si la ligne ne sera pas en attente d'être complétée ou **le code
**			ASCII** du caractère ouvrant l'attente,
**			ou **-1** en cas d'erreur.
*/

int	quotes(char **line)
{
	char	*tmp;
	int		i;
	int		q;

	if (line)
	{
		tmp = *line;
		i = -1;
		q = 0;
		while (tmp[++i])
			if (tmp[i] == '\'' || tmp[i] == '\"' || tmp[i] == '`'
				|| ((tmp[i] == '\\' || tmp[i] == '|' || tmp[i] == '&')
					&& !tmp[i + 1]))
			{
				if (!q)
					q = tmp[i];
				else if (q == tmp[i])
					q = 0;
			}
		if (i > 0 && q == '\\')
			tmp[i - 1] = ' ';
		return (q);
	}
	return (-1);
}
