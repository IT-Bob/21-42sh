#include "libmt.h"

size_t		ft_intlen(int n)
{
	size_t		i;

	i = 1;
	if (n == 0)
		return (1);
	while (n /= 10)
		i++;
	return (i);
}
