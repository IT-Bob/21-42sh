#include "sh.h"

static char	*shlvl_inc(char *str)
{
	char	*shlvl;

	shlvl = NULL;
	if (!ft_isdigit(str[0]))
		return (ft_strdup("1"));
	else
	{
		shlvl = ft_itoa(ft_atoi(str));
		if (ft_strcmp(shlvl, str))
		{
			ft_strdel(&shlvl);
			return (ft_strdup("1"));
		}
		ft_strdel(&shlvl);
		if (ft_atoi(str) == 2147483647)
			return (ft_strdup("1"));
		shlvl = ft_itoa(ft_atoi(str) + 1);
		return (shlvl);
	}
}

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
	char	*shlvl;
	char	*tmp;

	env = NULL;
	if (!environ || !environ[0])
	{
		if ((env = (char**)ft_memalloc(sizeof(char*) * (2 + 1))))
		{
			if (!(env[0] = ft_strdup("SHLVL=1")))
				ag_strdeldouble(&env);
		}
	}
	else
		env = dupenv((const char**)environ, ag_strlendouble((char **)environ));
	if ((shlvl = ft_getenv("SHLVL", (const char **)env)))
	{
		ft_vcontenv("SHLVL", (shlvl = shlvl_inc(shlvl)), &env);
		ft_strdel(&shlvl);
	}
	else
		ft_vcontenv("SHLVL", "1", &env);
	tmp = getcwd(NULL, 0);
	ft_vcontenv("PWD", tmp, &env);
	beacon_pwd(tmp);
	tmp ? ft_strdel(&tmp) : NULL;
	return (env);
}
