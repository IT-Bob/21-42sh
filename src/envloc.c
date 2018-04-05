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
