/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:46:32 by aguerin           #+#    #+#             */
/*   Updated: 2018/02/02 13:38:35 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strchr() renvoie le pointeur sur le caractère c, trouvé dans la chaîne s.
** Si c n'est pas trouvé dans s, NULL est renvoyé.
*/

char	*ft_strchr(const char *s, int c)
{
	while ((*s != c) && *s)
		s++;
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
