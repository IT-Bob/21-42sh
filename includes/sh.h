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

int			is_builtin(const char *arg);
char		**get_shbuiltin(void);

/*
**	execute.c
*/

int			execute(const char **argv, char **env);

/*
**	history.c
*/

t_lstag		*get_history(t_lstag *history);
int			history_builtin(const char **argv, t_lstag **history);

#endif
