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

void		get_term(int i)
{
	static struct termios	def;

	if (!i)
		tcgetattr(0, &def);
	else
		tcsetattr(0, 0, &def);
}

/*
**	\brief	Lancement des appels à la fonction `signal` pour les signaux à attraper
**
**	Les signaux attrapés et ignorés par le Shell sont :
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

