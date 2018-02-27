# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/11 14:50:14 by mtacnet           #+#    #+#              #
#    Updated: 2018/02/19 12:44:32 by mtacnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 21sh

GREEN		= "\033[32m"
RESET		= "\033[0m"

# src / obj files
SRC			= sh.c \

OBJ			= $(addprefix $(OBJDIR),$(SRC:.c=.o))
INC			= $(INCDIR)sh.h

# compiler
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# ft library
FT			= modules/libft/
FT_LIB 		= $(addprefix $(FT),libft.a)
FT_INC 		= -I modules/libft/includes/
FT_LNK 		= -L modules/libft -l ft

# directories
SRCDIR		= ./src/
INCDIR		= ./includes/
OBJDIR		= ./obj/

all: obj $(FT_LIB) $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c $(INC)
		$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		@make -C $(FT)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(FT_LNK) -lm -o $(NAME)
		@echo $(GREEN)"Compilation done !" $(RESET)

clean:
		@rm -rf $(OBJDIR)
		@make -C $(FT) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re
