#include "sh.h"
#include "expansion.h"

/*
**	Fonction de libération de mémoire passée a ag_lstdel()
*/

static void		del(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
		ft_memdel(&content);
}

/*
**	Transformation de la liste en une chaîne de caractères
*/

static char		*list_to_str(t_lstag *list)
{
	int		len;
	char	*str;
	t_lstag	*head;

	head = list;
	len = 0;
	while (list)
	{
		len += list->content_size - 1;
		list = list->next;
	}
	list = head;
	if (!(str = ft_strnew(len)))
		sh_error(1, "in list_to_str function");
	while (str && list)
	{
		str = ft_strcat(str, list->content);
		list = list->next;
	}
	return (str);
}

/*
**	Suppression du backslash en fin de ligne, ou ajout d'un retour à la ligne
**	si l'attente était faite sur une quote
*/

static void		alter_line(char **line, char c)
{
	char	*tmp;

	if (c > 0)
	{
		if (c == '\\')
			line[0][ft_strlen(*line) - 1] = ' ';
		else if (c == '"' || c == '\'' || c == '`')
		{
			tmp = ft_strnew(ft_strlen(*line) + 1);
			tmp = ft_strcpy(tmp, *line);
			tmp = ft_strcat(tmp, "\n");
			ft_strdel(line);
			*line = tmp;
		}
	}
}

static t_lstag	*read_line(t_lstag *history, char **var)
{
	int		c;
	char	*line;
	t_lstag	*list;
	t_lstag	*node;

	list = NULL;
	c = 0;
	while (1)
	{
		list ? (void)ft_putchar('\n') : NULL;
		if ((line = line_input(ft_getenv(list ? "PS2" : "PS1",\
				(const char**)var), history, var, get_shbuiltin())))
		{
			alter_line(&line, (c = quotes(&line, c)));
			node = ag_lstnew(line, ft_strlen(line) + 1);
			if (list)
				ag_lstaddtail(&list, node);
			else
				list = node;
			line ? ft_strdel(&line) : NULL;
			if (c <= 0 || !list)
				break ;
		}
		else
			break ;
	}
	return (list);
}

/*
**	\brief	Appel de l'édition de ligne
**
**	Appelle l'édition de ligne tant qu'une quote est ouverte,
**	ou qu'un backslash est en fin de ligne
**
**	\return	**commande** ou **NULL** en cas d'erreur
*/

char			*call_line(t_lstag **history, char *hist_file, char **var)
{
	char	*line;
	t_lstag	*list;
	t_lstag	*hd;

	list = read_line(history ? *history : NULL, var);
	sh_launchsignal();
	line = list_to_str(list);
	hd = heredoc(line, var, get_shbuiltin());
	hd ? ag_lstdel(&hd, del) : NULL;
	sh_launchsignal();
	list ? ag_lstdel(&list, del) : NULL;
	ft_putendl("");
	if (ft_expand_exclam(&line, *history) < 0)
		exit(EXIT_FAILURE); //need to be fixed
	*history = add_history(*history, hist_file, line);
	*history ? *history = ag_lsthead(*history) : NULL;
	return (line);
}
