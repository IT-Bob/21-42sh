NAME	= libmt.a

CC		= gcc

RM		= rm -rf

LIBFT_INC = includes/


CFLAGS	= -Wall -Wextra -Werror -c -I $(LIBFT_INC) -I includes/

SRC_PATH =	src/
SRC_FILE =	ft_countword.c ft_intlen.c ft_strjoinfree.c \
			ft_strlenint.c ft_tab.c view_tab.c

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILE))

OBJS	= $(SRCS:.c=.o)

GREEN	= "\033[32m"
ROUGE	= "\033[31m"
all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "$(ROUGEC)Suppression des fichiers objets de $(NAME)$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(ROUGEC)Suppression de la bibliothèque $(NAME)$(RESET)"
	@$(RM) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
