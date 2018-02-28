/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 13:26:34 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/31 14:57:05 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMT_H
# define LIBMT_H

# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		t_elem
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_elem;


int					ft_countword(const char *str, char c);
int					ft_isspace(int c);
int					ft_strlenint(const char *s);
char				*ft_strjoinfree(char *s1, char *s2, int mode);
void				supp_elem_tab(char **tab, int value);
void				free_tab(char **tab);
void				view_tab(char **tab);
size_t				ft_intlen(int c);


#endif
