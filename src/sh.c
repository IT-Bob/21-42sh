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

char		**concat_tab(char **env, char **local)
{
	int		len;
	int		i;
	int		j;
	char	**t;

	t = NULL;
	if ((len = ag_strlendouble(env) + ag_strlendouble(local)))
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
			sh_error(1, "21sh: concat_tab");
	}
	return (t);
}

static char	*call_line(t_lstag **history, char *hist_file, char **env)
{
	char	*line;
	char	*tmp;
	char	**built;
	char	**var;

	tmp = NULL;
	var = concat_tab(env, NULL);
	line = line_input("$>", *history, var, (built = get_shbuiltin()));
	while (line && quotes(&line) > 0)
	{
		ft_putendl("");
		if ((tmp = line_input(">", *history, var, (built = get_shbuiltin()))))
		{
			if (!(line = ag_strfreejoin(line, tmp)))
				sh_error(1, "21sh: call_line");
			ft_strdel(&tmp);
		}
	}
	*history = add_history(*history, hist_file, line);
	var ? ag_strdeldouble(&var) : NULL;
	*history ? *history = ag_lsthead(*history) : NULL;
	ft_putendl("");
	return (line);
}

int			main(int argc, char **argv, char **environ)
{
	char	**env;
	char	**built;
	char	*line;
	t_tok	*token;
	t_exec	*exe;
	t_lstag	*history;
	char	**local;
	char **test;

	token = NULL;
	exe = NULL;
	line = NULL;
	if (!(env = create_env((const char**)environ)))
		return (sh_error_int(1, "21sh: environnement cannot be created."));
	if (!(local = create_loc((const char**)env)))
		return (sh_error_int(1, "21sh: local cannot be created."));
	get_env(&env);
	get_loc(&local);
	history = init_history((const char**)env, (const char**)local);
	while (1)
	{
		history ? history = ag_lsthead(history) : NULL;
		history ? get_history(&history) : NULL;
		if (!(line = call_line(&history, get_history_file(NULL), env)) || ft_strnequ("exit", line, 4))
		{
			env ? ag_strdeldouble(&env) : NULL;
			line ? ft_strdel(&line) : NULL;
			if ((built = get_shbuiltin()))
				ft_memdel((void**)&built);
			history ? delete_history_list(&history) : NULL;
			return (1);
		}
		if ((token = lexer(line)))
		{
			if (parser(token) == NULL)
				return (-1);
			if (!(exe = create_final_lst(&token)))
				return (-1);
			if (parsing_error(exe) == -1)
			{
				freelst_exec(&exe);
				exe = NULL;
				return (-1);
			}
			else
				//view_exec_lst(&exe);
				exec(&exe, &env, &local);
			if (token)
				freelst(&token);
			freelst_exec(&exe);
		}
		test = ft_strsplit(line, ' ');
		test ? ag_strdeldouble(&test) : NULL;
		line ? ft_strdel(&line) : NULL;
	}
	(void)argc;
	(void)argv;
	return (0);
}
