#include "sh.h"

/*
**	\brief	Obtention de l'environnement
**
**	_Sigleton_ permettant d'obtenir et de mettre à jour le pointeur sur les
**	variables d'environnement.
**	La fonction doit être appelée une première fois avec `env` non nul afin
**	d'initialiser le sigleton. Les appels suivants peuvent être effectués avec
**	`env` nul pour seulement obtenir le pointeur,
**	ou non nul pour le mettre à jour
**
**	\param	env	- pointeur sur la tête de liste
**
**	\return	pointeur sur l'**environnement** ou **NULL**
**			si celui-ci n'existe pas ou que le pointeur n'a pas été initialisé
*/

char	***get_env(char ***env)
{
	static char	***e = NULL;

	if (env)
		e = env;
	return (e);
}

/*
**	\brief	Création des variables d'environnement
**
**	La fonction créée le tableau des variables d'environnement,
**	elle y copie l'environnement actuel si celui-ci existe ou en initialise
**	un nouveau sinon, contenant :
**	- PWD : répertoire actuel,
**	- SHLVL : niveau du Shell,
**
**	\param	environ	- environnement à copier
**
**	\return	**variables d'environnement** ou **NULL** en cas d'erreur
*/

char	**create_env(const char **environ)
{
	char	**env;
	char	*tmp;
	char	*tmp1;

	env = NULL;
	if (!environ || !environ[0])
	{
		if ((env = (char**)ft_memalloc(sizeof(char*) * (2 + 1))))
		{
			tmp = getcwd(NULL, 0);
			tmp1 = ft_strjoin("PWD=", tmp);
			if (!(env[0] = ft_strdup("SHLVL=1")) || !(env[1] = ft_strdup(tmp1)))
				ag_strdeldouble(&env);
			tmp ? ft_strdel(&tmp) : NULL;
			tmp1 ? ft_strdel(&tmp1) : NULL;
		}
	}
	else
		env = dupenv((const char**)environ, ag_strlendouble((char **)environ));
	return (env);
}
