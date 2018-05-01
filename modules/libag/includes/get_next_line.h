/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:06:08 by aguerin           #+#    #+#             */
/*   Updated: 2018/05/01 17:38:35 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4096
# define MAX_FD 10000

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
