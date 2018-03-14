#include "sh.h"

static char	**set_env(void)
{
	char	**env;
	char	*tmp;
	char	*tmp1;

	if ((env = (char**)ft_memalloc(sizeof(char*) * (2 + 1))))
	{
		tmp = getcwd(NULL, 0);
		tmp1 = ft_strjoin("PWD=", tmp);
		if (!(env[0] = ft_strdup("SHLVL=1")) || !(env[1] = ft_strdup(tmp1)))
			ag_strdeldouble(&env);
		tmp ? ft_strdel(&tmp) : NULL;
		tmp1 ? ft_strdel(&tmp1) : NULL;
	}
	return (env);
}

static char	**create_env(char **environ)
{
	char	**env;

	env = NULL;
	if (environ)
	{
		if (environ[0] == NULL)
			env = set_env();
		else
			env = dupenv((const char**)environ, ag_strlendouble(environ));
	}
	return (env);
}

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
		ft_putendl_fd(
			"21sh: allocation error in concat_tab() function", 2);
	}
	return (t);
}

static char	*call_line(t_lstag **history, char *hist_file, char **env)
{
	char	*line;
	char	**built;
	char	**var;

	var = concat_tab(env, NULL);
	line = line_input("$>", *history, var, (built = get_shbuiltin()));
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
	t_lstag	*history;

	char **test;

	line = NULL;
	history = read_history(get_history_file("./.21sh_history"), NULL);
	if (!(env = create_env(environ)))
		return (ft_putendl_fd("21sh: create environnement impossible.", 2));
	while (1)
	{
		history ? history = ag_lsthead(history) : NULL;
		get_history(&history);
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
			parser(token);
			freelst(&token);
		}
		test = ft_strsplit(line, ' ');
		execute((const char**)test, env);
		test ? ag_strdeldouble(&test) : NULL;
		line ? ft_strdel(&line) : NULL;
	}
	(void)argc;
	(void)argv;
	return (0);
}
