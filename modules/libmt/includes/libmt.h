#ifndef LIBMT_H
# define LIBMT_H

# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_elem
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_elem;

int					ft_countword(const char *str, char c);
int					ft_isspace(int c);
int					ft_strlenint(const char *s);
void				supp_elem_tab(char **tab, int value);
void				free_tab(char **tab);
void				view_tab(char **tab);
char				*ft_strjoinfree(char *s1, char *s2, int mode);
size_t				ft_intlen(int c);

#endif
