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
t_lstag		*init_history(const char **env, const char **loc);

/*
**	quotes.c
*/

int			quotes(char **line);

/*
**	variables.c
*/

char	***get_loc(char ***loc);
char	***get_env(char ***env);
char	*getenvloc(const char *name, const char **loc, const char **env);
char	**create_loc(const char **env);
char	**create_env(const char **environ);

#endif
