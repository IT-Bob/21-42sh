#include "sh.h"

/*
**	\brief	Fonction appelée par `signal` 
*/

static void	sh_signal(int signal)
{
	if (signal == SIGINT)
		NULL;
	ft_putendl("");
}

/*
**	\brief	Lancement des appels à la fonction `signal` pour les signaux à attraper
**
**	Les signaux attraper et ignorer par le Shell sont :
**
**	- SIGINT
**	- SIGTSTP
*/

void		sh_launchsignal(void)
{
	signal(SIGINT, sh_signal);
	signal(SIGTSTP, sh_signal);
}

/*
**	\brief	Restauration du comportement par défaut pour les signaux attrapés
*/

void		sh_resetsignal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
}

