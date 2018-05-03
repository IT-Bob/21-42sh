#include "libft.h"
#include <unistd.h>

int	ft_putstr(char const *str)
{
	if (!str)
		return (-1);
	return (write(1, str, ft_strlen(str)));
}
