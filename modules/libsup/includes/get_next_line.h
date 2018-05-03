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
