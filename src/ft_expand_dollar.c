#include "sh.h"

/*
**	Banales fonctions de reconnaissance de char.
*/

static int	ft_isredir(int c)
{
	if (c == '<')
		return (1);
	else if (c == '>')
		return (2);
	else if (c == '&')
		return (3);
	else if (c == ';')
		return (4);
	else if (c == '|')
		return (5);
	return (0);
}

static int	ft_isalpha_und(int c)
{
	if (ft_isalpha(c))
		return (1);
	else if (c == '_')
		return (1);
	else
		return (0);
}

static int	ft_aft_dol(char *str)
{
	if (ft_isdigit(str[0]))
		return (1);
	else if (ft_isalpha_und(str[0]))
		return (1);
	else if (str[0] == '?')
		return (1);
	else
		return (0);
}

/*
**	Les deux fonctions qui suivent servent a identifier les cas ou l'on
**	replace le '~' dans notre ligne de commande.
**
**	la premiere check si se qu'il y a avant le tild est valide.
**	la second check se qu'il y a apres.	
*/

static int	check_before(char *str, int index)
{
	if (str[index] == '~')
	{

		if (!index)
			return (1);
		index--;
		if (ft_isredir(str[index]) || ft_isspace(str[index]))
		{
			while (ft_isspace(str[index]) && index)
				index--;
			if (ft_isredir(str[index]))
			{
				if (ft_isredir(str[index]) == 1 && index)
				{
					if (ft_isredir(str[index - 1]) == 1)
						return (0);
				}
			}
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

static int	tild_k(char *str, int i)
{
	if (str[i] == '~' && check_before(str, i))
	{
		i++;
		if (str[i] == '/')
			return (1);
		else if (ft_isspace(str[i]))
			return (1);
		else if (!str[i])
			return (1);
		else if (ft_isredir(str[i]))
			return (1);
		else
			return (0);
	}
	return (0);
}

/*
**	Meme chose que pour le tild sauf qu'ici c'est pour le dollar.
*/

static int	ft_end_dollar(char *str)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (ft_isdigit(str[i]) || str[i] == '?')
		return (1);
	else if (ft_isalpha_und(str[i]))
	{
		while (ft_isalpha_und(str[i]) || ft_isdigit(str[i]))
		{
			i++;
			ret++;
		}
		return (ret);
	}
	return (0);
}

/*
**	Cette fonction recupere les valeurs des variables d'environnement et local,
**	a partir d'une string de recherche.
*/

static char	*ft_get_var(char *str, const char **env, const char **local)
{
	char	*tmp;
	char	*ret;
	int		i;

	
	i = 0;
	if (!(ret = ft_memalloc(sizeof(char) * (ft_end_dollar(str) + 1))))
		return (sh_error(1, "Dollar"));
	if (ft_isdigit(str[i]))
		ret[i] = str[i];
	else if (ft_isalpha_und(str[i]))
	{
		ret[i] = str[i];
		i++;
		while (ft_isalpha_und(str[i]) || ft_isdigit(str[i]))
		{
			ret[i] = str[i];
			i++;
		}
	}
	tmp = getenvloc(ret, (const char **)local, (const char **)env);
	ft_memdel((void **)&ret);
	return (tmp);
}

/*
**	Cette fonction renvoie la longueur de la string finale pour pouvoir malloc.
*/

static int	ft_malloc_dollar(char *str, const char **env, const char **local)
{
	char	*cmd;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] == '$' && ft_aft_dol(str + i + 1)) || tild_k(str, i))
		{
			if (ft_isalpha_und(str[i + 1]) || ft_isdigit(str[i + 1]))
				cmd = ft_get_var(str + i + 1, env, local);
			else if (str[i + 1] == '?')
				cmd = getenvloc("?", local, env);
			else if (tild_k(str, i))
				cmd = getenvloc("HOME", local, env);
			if (cmd)
				len += ft_strlen(cmd);
			i += ft_end_dollar(str + i + 1) + 1;
		}
		else
			i += (++len ? 1 : 0);
	}
	return (len + 1);
}

/*
**	Cette fonction ecrit sur la string malloc, qu'elle renvoie.
*/

static char	*ft_write_dollar(char *dest, char *str, const char **env,\
													const char **local)
{
	char	*cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '$' && ft_aft_dol(str + i + 1)) || tild_k(str, i))
		{
			if (ft_isalpha_und(str[i + 1]) || ft_isdigit(str[i + 1]))
				cmd = ft_get_var(str + i + 1, env, local);
			else if (str[i + 1] == '?')
				cmd = getenvloc("?", local, env);
			else if (tild_k(str, i))
				cmd = getenvloc("HOME", local, env);
			if (cmd)
			{
				ft_strcpy(dest + j, cmd);
				j += ft_strlen(cmd);
			}
			i += ft_end_dollar(str + i + 1) + 1;
		}
		else
			dest[j++] = str[i++];
	}
	return (dest);
}

/*
**	Cette fonction est la fonction principale.
**	Son but est de changer tout les '$' suivit d'une string ou d'un chiffreo
**	ou d'un '?' par les valeurs contenu dans l'env et le local.
*/

int			ft_expand_dollar(char **cmd, const char **env, const char **local)
{
	char	*ret;
	int		len;

	if (!ft_strchr((*cmd), '$') && !ft_strchr((*cmd), '~'))
		return (0);
	if (!(len = ft_malloc_dollar(*cmd, env, local)))
		return (-1);
	if (!(ret = ft_memalloc(sizeof(char) * len)))
		return (sh_error_int(1, "Expand"));
	if (!(ret = ft_write_dollar(ret, *cmd, env, local)))
		return (-1);
	ft_strdel(cmd);
	(*cmd) = ret;
	return (0);
}
