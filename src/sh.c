#include "sh.h"

int	main(void)
{
	extern char	**environ;
	char		**env;

	if ((env = dupenv((const char**)environ, ag_strlendouble(environ))))
	{
		ft_putendl("ok");
	}
	else
		ft_putendl("pas ok");
	return (0);
}
