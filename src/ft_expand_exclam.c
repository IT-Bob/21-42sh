/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_exclam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:18:39 by heinfalt          #+#    #+#             */
/*   Updated: 2018/05/01 17:18:43 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "expansion.h"

/*
**	Les deux fonction suivantes donnent pour les cmd de l'hist pour:
**	- le cas des digits.
**	- le cas des alphas.
*/

static char		*ft_digit_node(t_lstag *hist, int nb)
{
	int		move;
	int		lst_len;

	lst_len = ag_lstcountelem(hist);
	if (nb > lst_len || nb < -lst_len)
		return (NULL);
	if (nb > 0)
		move = lst_len - nb;
	else if (nb < 0)
		move = (nb + 1) * -1;
	else
		return (NULL);
	while (move)
	{
		hist = hist->next;
		move--;
	}
	return (hist->content);
}

static char		*ft_alpha_node(t_lstag *hist, char *str)
{
	t_lstag		*find;
	char		*search;
	int			i;

	i = 0;
	while (ft_isalpha(str[i]))
		i++;
	if (!(search = ft_memalloc(sizeof(char) * (i + 1))))
		return (sh_error(1, "Expand"));
	i = 0;
	while (ft_isalpha(str[i]))
	{
		search[i] = str[i];
		i++;
	}
	if (!(find = search_history_begin(hist, search)))
	{
		ft_memdel((void **)&search);
		return (NULL);
	}
	ft_memdel((void **)&search);
	return (find->content);
}

/*
**	Les deux fonctions suivantes font chacune:
**	- Donne la longueur de la string finale.
**	- Ecrit la string finale.
*/

static int		ft_malloc_exclam(char *str, t_lstag *hist)
{
	char		*cmd;
	int			len;
	int			i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '!' && ft_after_exclam(str + i + 1))
		{
			if (ft_isdigit((str[i + 1] == '-' ? str[i + 2] : str[i + 1])))
				cmd = ft_digit_node(hist, ft_atoi(str + i + 1));
			else if (ft_isalpha(str[i + 1]))
				cmd = ft_alpha_node(hist, (str + i + 1));
			else if (str[i + 1] == '!')
				cmd = ft_digit_node(hist, -1);
			if (!cmd)
				return (ft_enf((str + i + 1), 0));
			len += ft_strlen(cmd);
			i += ft_end_exclam(str + i + 1);
		}
		else
			i += (++len ? 1 : 0);
	}
	return (len + 1);
}

static char		*ft_write_exclam(char *dest, char *str, t_lstag *hist, int i)
{
	char		*cmd;
	int			j;

	j = 0;
	while (str[i])
	{
		if (str[i] == '!' && ft_after_exclam(str + i + 1))
		{
			if (ft_isdigit((str[i + 1] == '-' ? str[i + 2] : str[i + 1])))
				cmd = ft_digit_node(hist, ft_atoi(str + i + 1));
			else if (ft_isalpha(str[i + 1]))
				cmd = ft_alpha_node(hist, (str + i + 1));
			else if (str[i + 1] == '!')
				cmd = ft_digit_node(hist, -1);
			if (!cmd)
				return ((ft_enf((str + i + 1), 0) ? NULL : NULL));
			ft_strcpy(dest + j, cmd);
			j += ft_strlen(cmd);
			i += ft_end_exclam(str + i + 1);
		}
		else
			dest[j++] = str[i++];
	}
	return (dest);
}

/*
**	C'est la fonction principale du fichier.
**	Elle recoit un pointer sur la ligne de cmd et sur l'historique.
**	---------------------------------------------------
**	L'objectif est de remplacer tout les '!' suivient d'un digit (pos/neg)
**	ou d'un alpha (un '!' suivant un autre '!' est remplace par "!-1"
**	et compte comme un digit) par la cmd de l'historique qui correspond.
**	(les digits neg commence par les derniere commande et inversement pour
**	les positifs).
*/

int				ft_expand_exclam(char **cmd, t_lstag *hist)
{
	char		*ret;
	int			len;

	if (!ft_strchr(*cmd, '!'))
		return (0);
	if (!(len = ft_malloc_exclam(*cmd, hist)))
		return (-1);
	if (!(ret = ft_memalloc(sizeof(char) * len)))
		return (sh_error_int(1, "Expand"));
	if (!(ret = ft_write_exclam(ret, (*cmd), hist, 0)))
		return (-1);
	ft_strdel(cmd);
	(*cmd) = ret;
	ft_putendl(ret);
	return (0);
}
