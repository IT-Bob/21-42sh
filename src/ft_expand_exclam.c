#include "sh.h"

/*
**	Cette fonction check si ce qui suit le '!' est un cas d'expansion.
*/

static int	ft_after_exclam(char *str)
{
	if (ft_isdigit((str[0] == '-' ? str[1] : str[0])))
		return (1);
	else if (ft_isalpha(str[0]))
		return (1);
	else if (str[0] == '!')
		return (1);
	else
		return (0);
}

/*
**	Cette fonction est utilisee pour retournee les erreurs.
**	Elle affiche un "event not found" sur la sortie d'erreur.
**	Elle affiche aussi l'event concerne.
*/

static int	ft_enf(char *cmd, int val)
{
	char	*display;
	int		digit;
	int		i;

	i = (cmd[0] == '-' ? 1 : 0);
	digit = (ft_isdigit(cmd[i]) ? 1 : 0);
	while ((digit ? ft_isdigit(cmd[i]) : ft_isalpha(cmd[i])))
		i++;
	if (!(display = ft_memalloc(sizeof(char) * (i + 2))))
		return (sh_error_int(1, "Expand"));
	i = (cmd[0] == '-' ? 1 : 0);
	display[0] = '!';
	if (i)
		display[1] = '-';
	while ((digit ? ft_isdigit(cmd[i]) : ft_isalpha(cmd[i])))
	{
		display[i + 1] = cmd[i];
		i++;
	}
	ft_putstr_fd("ERROR: event not found: ", 2);
	ft_putendl_fd(display, 2);
	return (val);
}

/*
**	Cette fonction permet de faire suivre a l'index la suite des operations
**	apres avoir rencontre un '!' dans la string de depart.
*/

static int ft_end_exclam(char *str)
{
	int		ret;

	ret = 0;
	if (ft_isdigit((str[0] == '-' ? str[1] : str[0])))
		ret += ag_nbrlen(ft_atoi(str));
	else if (ft_isalpha(str[0]))
	{
		while (ft_isalpha(str[ret]))
			ret++;
	}
	else if (str[0] == '!')
		ret++;
	else
		return (1);
	return (ret + 1);
}

/*
**	Les deux fonction suivantes donnent pour les cmd de l'hist pour:
**	- le cas des digits.
**	- le cas des alphas.
*/

static char *ft_digit_node(t_lstag *hist, int nb)
{
	int		move;
	int		lst_len;

	lst_len = ag_lstcountelem(hist);
	if (nb > lst_len || nb < -lst_len) // care MAX VALUE
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

static char *ft_alpha_node(t_lstag *hist, char *str)
{
	t_lstag	*find;
	char	*search;
	int		i;

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

static int	ft_malloc_exclam(char *str, t_lstag *hist)
{
	char	*cmd;
	int		len;
	int		i;

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

static char *ft_write_exclam(char *dest, char *str, t_lstag *hist)
{
	char	*cmd;
	int		i;
	int		j;

	i = 0;
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

int			ft_expand_exclam(char **cmd, t_lstag *hist)
{
	char	*ret;
	int		len;

	if (!ft_strchr(*cmd, '!'))
		return (0);
	if (!(len = ft_malloc_exclam(*cmd, hist)))
		return (-1);
	if (!(ret = ft_memalloc(sizeof(char) * len)))
		return (sh_error_int(1, "Expand"));
	if (!(ret = ft_write_exclam(ret, (*cmd), hist)))
		return (-1);
	ft_strdel(cmd);
	(*cmd) = ret;
	ft_putendl(ret);
	return (0);
}