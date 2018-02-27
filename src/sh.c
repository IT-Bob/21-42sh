#include "sh.h"

static char		**set_env(void)
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

static char		**create_env(char **environ)
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

int				main(void)
{
	extern char		**environ;
	char			**env;

	if ((env = create_env(environ)))
	{
		ft_putendl_fd("env create", 2);
		print_env((const char**)env);
	}
	else
		ft_putendl_fd("21sh: create environnement impossible.", 2);
	return (0);
}
