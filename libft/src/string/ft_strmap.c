/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:42:07 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:10:08 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** pour créer une nouvelle chaine “fraiche” résultant des
** applications successives de f.
*/

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;
	int		i;

	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		if (len > 0)
		{
			str = (char*)ft_memalloc(sizeof(char) * (len + 1));
			if (str)
			{
				while (*s)
				{
					str[i++] = f(*s);
					s++;
				}
				str[i] = '\0';
				return (str);
			}
		}
	}
	return (NULL);
}
