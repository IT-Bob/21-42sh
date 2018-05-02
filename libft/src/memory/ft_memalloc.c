/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:22:05 by aguerin           #+#    #+#             */
/*   Updated: 2018/05/02 17:15:58 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** ft_memalloc() alloue la mémoire et remplie la zone allouée avec des 0.
*/

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void*)malloc(size);
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}
