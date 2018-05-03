#include "libft.h"
#include <unistd.h>

int	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return (-1);
	return (write(fd, s, ft_strlen(s)));
}
