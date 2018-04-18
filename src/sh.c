#include "sh.h"

/*
**	\brief	Initalisation des environnements et de l'historique
**
**	La fonction initialise les variables d'environnement, les variables locales
**	et la liste de l'historique.
**	Si la création/allocation des tableaux de variables échoue,
**	la fonction s'arrête et renvoie **1**.
**
**	\return	**0** en cas de succès ou **1** en cas d'erreur
*/

static int	init_sh(char ***env, char ***local, t_lstag	**history)
{
	extern char	**environ;

	if (env && local && history)
	{
		if (!(*env = create_env((const char**)environ)))
			return (sh_error_int(1, "21sh: environnement cannot be created."));
		if (!(*local = create_loc((const char**)*env)))
		{
			ag_strdeldouble(env);
			return (sh_error_int(1, "21sh: local cannot be created."));
		}
		get_env(env);
		get_loc(local);
		*history = init_history((const char**)*env, (const char**)*local);
		return (0);
	}
	return (1);
}

int			main(void)
{
	char	**env;
	char	**local;
	char	*line;
	t_lstag	*history;
	char	**built; // A SUPPRIMER

	sh_launchsignal();
	if (init_sh(&env, &local, &history))
		return (1);
	while (1)
	{
		history ? history = ag_lsthead(history) : NULL;
		history ? get_history(&history) : NULL;
		if (!(line = call_line(&history, get_history_file(NULL),\
								(const char**)env, (const char **)local))
			|| ft_strnequ("exit", line, 4)) // A SUPPRIMER
		{
			env ? ag_strdeldouble(&env) : NULL;
			local ? ag_strdeldouble(&local) : NULL;
			line ? ft_strdel(&line) : NULL;
			if ((built = get_shbuiltin()))
				ft_memdel((void**)&built);
			history ? delete_history_list(&history) : NULL;
			sh_resetsignal();
			return (1);
		}
		pre_exec(line, &env, &local);
		line ? ft_strdel(&line) : NULL;
	}
	return (0);
}
