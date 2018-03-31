#include "sh.h"

static int	exclamation_replace(char **line, t_lstag *history, int i)
{
	int	j;

	if (!line[0][i + 1] || ft_isspace(line[0][i + 1]))
		return (0);
	if (ft_isdigit(line[0][i + 1]))
	{
		j = ft_strchr(&(line[0][i]), ' ') - &(line[0][i]);
		return (ft_putstr_fd("\n21sh: ", 2) + (j > 0 ?\
			ag_putnstr_fd(&line[0][i], j, 2) : ft_putstr_fd(&line[0][i], 2))\
			+ ft_putstr_fd(" event not found", 2));
	}
	if (line[0][i + 1] == '-')
	(void)history;
	(void)i;
	return (0);
}

int			exclamation(char **line, t_lstag *history)
{
	int	i;
	int	ret;

	if (line && history)
	{
		i = -1;
		ret = 0;
		while (line[0][++i] && !ret)
			if (line[0][i] == '!')
				ret = exclamation_replace(line, history, i);
	}
	return (1);
}
