#include "sh.h"

/*
**	\brief	Regroupement de tableaux
**
**	Regroupe les tableaux de chaînes de caractères
**	(environnement et local) en un seul afin de pouvoir l'envoyer
**	à l'édition de ligne.
**
**	\param	env		- tableau contenant les variables d'environnement
**	\param	local	- tableau contenant les variables locales
**
**	\return **tableau** regroupant ceux donnés en paramètres
**			ou **NULL** en cas d'erreur
*/

char	**concat_tab(const char **env, const char **local)
{
	int		len;
	int		i;
	int		j;
	char	**t;

	t = NULL;
	if ((len = ag_strlendouble((char**)env) + ag_strlendouble((char**)local)))
	{
		if ((t = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		{
			i = -1;
			j = 0;
			while (t && env && env[++i])
				if (!(t[j++] = ft_strdup(env[i])))
					ag_strdeldouble(&t);
			i = -1;
			while (t && local && local[++i])
				if (!(t[j++] = ft_strdup(local[i])))
					ag_strdeldouble(&t);
		}
		if (!t)
			sh_error(1, "21sh: in function concat_tab");
	}
	return (t);
}