/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:30:32 by mtacnet           #+#    #+#             */
/*   Updated: 2018/01/17 13:57:14 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmt.h"

void	supp_elem_tab(char **array, int value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i] && array[i][0] != '\0')
		i++;
	if (value >= i)
		return ;
	else
	{
		while (j < i)
		{
			array[j] = array[j + 1];
			j++;
		}
	}
	return ;
}

void	free_tab(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		if (array[i] != NULL)
		{
			ft_strdel(&(array[i]));
			i++;
		}
		else
			i++;
	}
	free(array);
	array = NULL;
}
