#ifndef SH_H
# define SH_H

# include "libft.h"
# include "libag.h"
# include "libmt.h"
# include "environment.h"
# include "history.h"
# include "line_input.h"
# include "parser.h"
# include "liberror.h"
# include "libexec.h"

/*
**	builtin.c
*/

char		**get_shbuiltin(void);

/*
**	history.c
*/

t_lstag		**get_history(t_lstag **history);
char		*get_history_file(const char *file);
int			history(char **command, t_lstag **history);

/*
**	quotes.c
*/

int			quotes(char **line);

#endif
