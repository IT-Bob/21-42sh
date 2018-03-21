#include "../includes/error.h"

void	error(int val)
{
	if (val == 1)
	{
		ft_putendl_fd("ERROR: MEMORY ALLOCATION", 2);
		return ;
	}
}

int		main(void)
{
	error(1);
	return (0);
}
