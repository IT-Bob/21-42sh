/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:42:36 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/16 14:00:43 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s)
	{
		str = (char*)ft_memalloc(sizeof(char) * (len + 1));
		if (str)
		{
			i = 0;
			while (len > 0)
			{
				str[i] = s[start];
				start++;
				len--;
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
