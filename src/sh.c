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

static char	**concat_tab(const char **env, const char **local)
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

/*
**	\brief	Appel de l'édition de ligne
**
**	Appelle l'édition de ligne tant qu'une quote (ou parenthèse, etc..)
**	est ouverte, ou qu'un backslash est en fin de ligne
**
**	\return	**commande** ou **NULL** en cas d'erreur
*/

static char	*call_line(t_lstag **history, char *hist_file,\
						const char **env, const char **local)
{
	char	*line;
	char	*tmp;
	char	**built;
	char	**var;

	tmp = NULL;
	var = concat_tab(env, local);
	built = get_shbuiltin();
	line = line_input(getenvloc("PS1", local, env), *history, var, built);
	while (line && quotes(&line) > 0)
	{
		ft_putendl("");
		if ((tmp = line_input(">", *history, var, built)))
		{
			if (!(line = ag_strfreejoin(line, tmp)))
				sh_error(1, "21sh: call_line");
			ft_strdel(&tmp);
		}
	}
	sh_launchsignal();
	*history = add_history(*history, hist_file, line);
	var ? ag_strdeldouble(&var) : NULL;
	*history ? *history = ag_lsthead(*history) : NULL;
	ft_putendl("");
	return (line);
}

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
		sh_launchsignal();
		pre_exec(line, &env, &local);
		line ? ft_strdel(&line) : NULL;
	}
	return (0);
}
