#include "sh.h"

/*
**	\brief	Lancement des builtins
**
**	\param	argv	- commande suivie de ses éventuels paramètres
**
**	\return	**0** en cas de succès ou une valeur **non nulle** sinon
*/

static int	call_builtin(const char **argv)
{
	t_lstag	**history;

	history = get_history(NULL);
	if (ft_strequ(argv[0], "builtin"))
		ft_putendl_fd("lancement de builtin", 2);
	else if (ft_strequ(argv[0], "cd"))
		ft_putendl_fd("lancement de cd", 2);
	else if (ft_strequ(argv[0], "echo"))
		ft_putendl_fd("lancement de echo", 2);
	else if (ft_strequ(argv[0], "env"))
		ft_putendl_fd("lancement de env", 2);
	else if (ft_strequ(argv[0], "exit"))
		ft_putendl_fd("lancement de exit", 2);
	else if (ft_strequ(argv[0], "history"))
		return (history_builtin(argv, history ? history : NULL));
	else if (ft_strequ(argv[0], "setenv"))
		ft_putendl_fd("lancement de setenv", 2);
	else if (ft_strequ(argv[0], "unsetenv"))
		ft_putendl_fd("lancement de unsetenv", 2);
	else if (ft_strequ(argv[0], "!"))
		ft_putendl_fd("lancement de !", 2);
	return (1);
}

/*
**	\brief	Lancement des exécutables
**
**	\param	argv	- commande suivie de ses éventuels paramètres
**
**	\return	**0** en cas de succès ou une valeur **non nulle** sinon
*/

static int	call_exec(const char **argv, char **env)
{
	ft_putstr_fd("execution de ", 2);
	ft_putendl_fd(argv[0], 2);
	if (env)
		NULL;
	return (1);
}

/*
**	\brief	Exécution des exécutables ou builtins
**
**	\param	argv	- commande à appelée (builtin ou exécutable)
**	\param	env		- environnement à envoyer à la commande
**
**	\return	**0** en cas de succès ou une valeur **non nulle** sinon
*/

int			execute(const char **argv, char **env)
{
	if (argv)
	{
		if (is_builtin(argv[0]))
			return (call_builtin((const char**)argv));
		else
			return (call_exec((const char**)argv, env));
	}
	return (1);
}
