#include "sh.h"

/*
**	\brief	Tableau indiquant les builtins du projet
**
**	La fonction renvoie un tableau dont chaque case contient le nom
**	d'un builtin du projet.
**	Seule la première dimension est allouée.
**
**	\return	**tableau** contenant le nom des builtins
**			ou **NULL** en cas d'erreur
*/

char	**get_shbuiltin(void)
{
	static char	**t = NULL;

	if (!t)
	{
		if ((t = (char**)ft_memalloc(sizeof(char*) * 8)))
		{
			t[0] = "cd";
			t[1] = "echo";
			t[2] = "env";
			t[3] = "exit";
			t[4] = "history";
			t[5] = "setenv";
			t[6] = "unsetenv";
		}
		else
			sh_error(1, "in function get_builtin");
	}
	return (t);
}
