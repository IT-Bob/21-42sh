#include "sh.h"

/*
**	\brief	Obtention de l'environnement
**
**	_Sigleton_ permettant d'obtenir et de mettre à jour le pointeur sur les
**	variables locales.
**	La fonction doit être appelée une première fois avec `loc` non nul afin
**	d'initialiser le sigleton. Les appels suivants peuvent être effectués avec
**	`loc` nul pour seulement obtenir le pointeur,
**	ou non nul pour le mettre à jour
**
**	\param	loc	- pointeur sur la tête de liste
**
**	\return	pointeur sur les **locales** ou **NULL**
**			si celui-ci n'existe pas ou que le pointeur n'a pas été initialisé
*/

char	***get_loc(char ***loc)
{
	static char	***l = NULL;

	if (loc)
		l = loc;
	return (l);
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
**	\brief	Recherche d'une variable dans les locales et dans l'environnement
**
**	La fonction cherche la variable dans l'environnement et dans les variables
**	locales.
**	Si la variable est présente dans les deux tableaux, la valeur de celle de
**	l'environnement est renvoyée.
**
**	\return	**valeur** de la variable ou **NULL** si elle n'existe pas
*/

char	*getenvloc(const char *name, const char **loc, const char **env)
{
	char	*value;

	value = NULL;
	if (!env || !(value = ft_getenv(name, env)))
		value = loc ? ft_getenv(name, loc) : NULL;
	return (value);
}

/*
**	\brief	Création des variables locales
**
**	La fonction créée le tableau de variables locales contenant :
**	- HISTFILE : chemin vers le fichier d'historique. L'historique est placé
**				 à la racine du dossier de l'utilisateur
**
**	\param	env	- environnement, utilisé pour récuper la variable "HOME"
**
**	\return	**variables locales** ou **NULL** en cas d'erreur
*/

char	**create_loc(const char **env)
{
	char	**loc;
	char	*tmp;
	char	*home;

	if ((loc = (char**)ft_memalloc(sizeof(char*) * (1 + 1))))
	{
		if ((home = ft_getenv("HOME", env)) && home[0])
		{
			if ((tmp = ft_strnew(ft_strlen(home) + 14)))
			{
				tmp = ft_strcpy(tmp, home);
				tmp = ft_strcat(tmp, "/.21sh_history");
				if (ft_vcontenv("HISTFILE", tmp, &loc))
					sh_error(1, "in function create_loc");
			}
			else
				ag_strdeldouble(&loc);
			if (ft_vcontenv("PS1", "$>", &loc))
				sh_error(1, "in function create_loc");
			tmp ? ft_strdel(&tmp) : sh_error(1, "in function create_loc");
		}
	}
	else
		sh_error(1, "in function create_loc");
	return (loc);
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
