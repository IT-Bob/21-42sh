#include "sh.h"

/*
**	\brief	Obtention de l'historique
**
**	_Sigleton_ permettant d'obtenir et de mettre à jour le pointeur sur la tête
**	de liste de l'historique.
**	La fonction doit être appelée une première fois avec `history` non nul afin
**	d'initialiser le sigleton. Les appels suivants peuvent être effectués avec
**	`history` nul pour seulement obtenir le pointeur,
**	ou non nul pour le mettre à jour
**
**	\param	history	- pointeur sur la tête de liste
**
**	\return	**tête de liste** de l'historique ou **NULL** si celui-ci n'existe pas
**			ou que le pointeur n'a pas été initialisé
*/

t_lstag		**get_history(t_lstag **history)
{
	static t_lstag	**h = NULL;

	if (history)
		h = history;
	return (h);
}

/*
**	\brief	Obtention du nom du fichier d'historique
**
**	_Sigleton_ permettant d'obtenir et de mettre à jour le nom du fichier
**	d'historique.
**	La fonction doit être appelée une première fois avec `file` non nul afin
**	d'initialiser le sigleton. Les appels suivants peuvent être effectués avec
**	`file` nul pour seulement obtenir le pointeur,
**	ou non nul pour le mettre à jour
**
**	\param	file	- non du fichier d'historique
**
**	\return	**tête de liste** de l'historique ou **NULL**
**			si celui-ci n'existe pas ou que le pointeur n'a pas été initialisé
*/

char		*get_history_file(const char *file)
{
	static char	*f = NULL;

	if (file)
		f = (char*)file;
	else
		f = getenvloc("HISTFILE", (const char**)*get_loc(NULL),
						(const char**)*get_env(NULL));
	return (f);
}

/*
**	\brief	Builtin d'historique
**
**	\param	command	- commande historique et ses éventuels paramètres
**	\param	history	- historique du shell
**
**	\return **1** en cas d'erreur ou **0** sinon
*/

int			history(char **command, t_lstag **history)
{
	if (command && history)
	{
		if (command[0] && !command[1])
			print_history(*history, -1);
		return (0);	
	}
	return (1);
}
