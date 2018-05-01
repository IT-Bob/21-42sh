/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:42:44 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 16:48:42 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** ft_strjoin() alloue la mémoire nécessaire pour concaténer les chaînes 's1'
** et 's2' et effectue la copie dans la nouvelle chaîne.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		str = (char*)ft_memalloc(sizeof(char) * (len + 1));
		if (str)
		{
			len = 0;
			while (*s1)
			{
				str[len++] = *s1;
				s1++;
			}
			while (*s2)
			{
				str[len++] = *s2;
				s2++;
			}
			str[len] = '\0';
			return (str);
		}
	}
	return (NULL);
}
