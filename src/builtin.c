#include "sh.h"

/**
**	\brief	Tableau indiquant les builtins du projet
**
**	La fonction renvoie un tableau dont chaque case contient le nom
**	d'un builtin du projet.
**	Seule la première dimension est allouée.
**
**	\return	**tableau** contenant le nom des builtins
**			ou **NULL** en cas d'erreur
*/

char **get_shbuiltin(void)
{
	static char	**t = NULL;

	if (!t)
	{
		if ((t = (char**)ft_memalloc(sizeof(char*) * 10)))
		{
			t[0] = "builtin";
			t[1] = "cd";
			t[2] = "echo";
			t[3] = "env";
			t[4] = "exit";
			t[5] = "history";
			t[6] = "setenv";
			t[7] = "unsetenv";
			t[8] = "!";
		}
		else
			ft_putendl_fd(
			"21sh: allocation error in get_builtin() function", 2);
	}
	return (t);
}
