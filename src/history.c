#include "sh.h"

/*
**	\brief	Obtention de l'historique
**
**	_Sigleton_ permettant d'obtenir et de mettre à jour le pointeur sur la tête
**	de liste de l'historique.
**	La fonction doit être appelé une première fois avec `history` non nul afin
**	d'initialiser le sigleton. Les appels suivants peuvent être effectués avec
**	`history` nul pour seulement obtenir le pointeur,
**	ou non nul pour le mettre à jour
**
**	\param	history	- pointeur sur la tête de liste
**
**	\return	**tête de liste** de l'historique ou **NULL** si celui-ci n'existe pas
**			ou que le pointeur n'a pas été initialisé
*/

t_lstag		*get_history(t_lstag *history)
{
	static t_lstag	*h = NULL;

	if (history)
		h = history;
	return (h);
}

static int	delete_command(t_lstag **history, int pos)
{
	t_lstag	*h;
	t_lstag	*prev;
	t_lstag	*next;

	if (pos > 0)
	{
		h = *history;
		h = ag_lsttail(h);
		while (--pos && h)
			h = h->prev;
		if (h)
		{
			prev = h->prev;
			next = h->next;
			if (prev)
			{
				prev->next = next;
				*history = ag_lsthead(prev);
			}
			if (next)
			{
				next->prev = prev;
				*history = ag_lsthead(next);
			}
			h->content ? ft_memdel((void**)&h->content) : NULL;
/*VERIF*/	h ? ft_memdel((void**)&h) : NULL;
		}
	}
	return (0);
}

/*
**	\brief	Builtin `history`
**
**	La fonction permet la gestion de l'historique du Shell.
**
**	\param	argv	- commande `history` et ses éventuels paramètres
**	\param	history	- liste contenant l'historique
**
**	\return	**0** si tout s'est bien déroulé
**			ou une **valeur non nulle** sinon
*/

int			history_builtin(const char **argv, t_lstag **history)
{
	int	cmp;
	int	i;
	int	err;

	err = 1;
	if (argv && argv[0] && history)
	{
		err = 0;
		cmp = -1;
		i = 0;
		while (argv[++i] && argv[i][0] == '-' && !err)
		{
			if (ft_strequ(argv[i], "-c"))
				delete_history_list(history);
			else if (ft_strequ(argv[i], "-d"))
			{
				if (argv[i + 1] && ft_isdigit(argv[++i][0]))
				{
					delete_command(history, ft_atoi(argv[i]));
					ft_putstr("Suppression de la commande ");
					ft_putnbr(ft_atoi(argv[i]));
					ft_putendl("");
					err = 1;
				}
				else
					err = ft_putendl_fd(
					"history: -d option needs a positive numerical argument", 2);
			}
			else
				err = ft_putendl_fd("history: bad option\nusage: history [-c] [n]", 2);
		}
		history && !err ? print_history(*history, cmp) : NULL;
	}
	return (err);
}
