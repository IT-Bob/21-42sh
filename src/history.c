#include "sh.h"

/**
**	\brief	Builtin `history`
**
**	La fonction permet la gestion de l'historique du Shell.
**
**	\param	argv	- commande `history` et ses éventuels paramètres
**	\param	history	- liste contenant l'historique
**
**	\return	**0** si tout s'est bien déroulé ou **1** sinon
*/

int	history_builtin(char **argv, t_lstag *history)
{
	int	cmp;

	if (argv && argv[0] && history)
	{
		cmp = -1;
		if (argv[1] && argv[1][0] != '-')
			cmp = ft_atoi(argv[1]);
		print_history(history, cmp);
	}
	return (1);
}
