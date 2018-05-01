/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:50:23 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/16 15:34:50 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strclr() met à 0 tous les caractères de la chaîne s.
*/

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (s)
		while (s[i])
			s[i++] = '\0';
}