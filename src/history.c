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

int	history_builtin(char **argv, t_lstag **history)
{
	int	cmp;
	int	i;

	if (argv && argv[0] && history)
	{
		cmp = -1;
		i = 0;
		while (argv[++i])
		{
			if (ft_strequ(argv[i], "-c"))
				delete_history_list(history);
		}
		history ? print_history(*history, cmp) : NULL;
	}
	return (1);
}
