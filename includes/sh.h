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
# include "heredoc.h"

/*
**	ft_expand.c
*/

int			ft_expand_exclam(char **cmd, t_lstag *hist);

/*
**	builtin.c
*/

char		**get_shbuiltin(void);

/*
**	environment.c
*/

char		***get_env(char ***env);
char		**create_env(const char **environ);

/*
**	history.c
*/

char		*get_history_file(const char *file);
t_lstag		*init_history(const char **env, const char **loc);

/*
**	line.c
*/

char		*call_line(t_lstag **history, char *hist_file,\
						const char **env, const char **local);

/*
**	local.c
*/

char		***get_loc(char ***loc);
char		**create_loc(const char **env);

/*
**	quotes.c
*/

int			quotes(char **line, char c);

/*
**	signal.c
*/

void		sh_launchsignal(void);
void		sh_resetsignal(void);

/*
**	tools.c
*/

char		**concat_tab(const char **env, const char **local);

/*
**	variables.c
*/

char		*getenvloc(const char *name, const char **loc, const char **env);

#endif
