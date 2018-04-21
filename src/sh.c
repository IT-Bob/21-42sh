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
	return (ft_putendl_fd("ERROR: 21sh: initialization failed", 2));
}

int			main(void)
{
	char	**env;
	char	**local;
	char	**var;
	char	*line;
	t_lstag	*history;

	env = NULL;
	local = NULL;
	history = NULL;
	sh_launchsignal();
	if (init_sh(&env, &local, &history))
		return (1);
	while (1)
	{
		history ? history = ag_lsthead(history) : NULL;
		history ? get_history(&history) : NULL;
		var = concat_tab((const char**)env, (const char**)local);
		if (!(line = call_line(&history, get_history_file(NULL), var)))
			exit_final(1);
		pre_exec(line, &env, &local);
		line ? ft_strdel(&line) : NULL;
		var ? ag_strdeldouble(&var) : NULL;
	}
	return (0);
}
