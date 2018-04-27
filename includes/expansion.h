#ifndef EXPANSION_H
# define EXPANSION_H

# include "libft.h"
# include "libag.h"
# include "libmt.h"

/*
**	ft_expand.c
*/

int			ft_expand_exclam(char **cmd, t_lstag *hist);
int			ft_expand_dollar(char **cmd, const char **env, const char **local, int check_tild);

#endif
