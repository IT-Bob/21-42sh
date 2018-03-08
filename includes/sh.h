#ifndef SH_H
# define SH_H

# include "libft.h"
# include "libag.h"
# include "libmt.h"
# include "environment.h"
# include "history.h"
# include "line_input.h"
# include "parser.h"

/*
**	builtin.c
*/

char		**get_shbuiltin(void);

/*
**	history.c
*/

int			history_builtin(char **argv, t_lstag *history);

#endif
