#include "sh.h"

/*
**	This function checks if what is  following '!' is
**	a case for expansion or not.
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
**	This function is used for error returns.
**	Giving an "event no found" or ENF on Error output.
**	Also displaying the "event" concerned.
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
**	This function allow the index on the initial string to follow 
**	the process after it encounters a '!'.
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
**	The two following funtions are giving the hist cmd for:
**	- digit cases.
**	- alpha cases.
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
**	The two following functions are, each:
**	- giving length of the final string.
**	- writing the final string.
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
**	This is the main function of the file.
**	It takes the history and a pointer on the cmd line.
**	---------------------------------------------------
**	The objectif is to replace any '!' followed by a digit (neg / pos)
**	or an alpha (a double '!' is egal to '!-1' and count as a digit)
**	with the numbered string for digit and the matching string in the case of alphas.
**	(neg digit is a roll back in hist and pos digit is from the start of hist)
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