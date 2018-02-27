# Nom
NAME = 21sh
PROJECT = 21sh

# Détection de l'OS
OS = $(shell uname -s)

# Options de compilation
CC = @gcc
CFLAGS = -Wall -Werror -Wextra
ifeq ($(OS), Linux)
	CFLAGSUP = -Wno-sign-compare -Wno-empty-body #-g -fsanitize=address
else
	CFLAGSUP = -Wno-sign-compare # -g -fsanitize=address
endif
CPPFLAGS = -I $(INC_PATH) -I $(LIB_INC) -I $(LIBAG_INC) -I $(ENV_INC)
CLIB = -L $(ENV) -lenv -L $(LIBAG) -lag -L $(LIBFT) -lft

# Fichiers d'en-tête
INC_PATH = includes/
INC_FILE = sh.h
INC = $(addprefix $(INC_PATH), $(INC_FILE))

# Fichiers sources
SRC_PATH = src/
SRC_FILE = sh.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

# Fichiers des bibliothèques
LIBFT = modules/libft/
LIB_INC = $(LIBFT)includes/
LIB_FT = $(LIBFT)libft.a

LIBAG = modules/libag/
LIBAG_INC = $(LIBAG)includes/
LIB_AG = $(LIBAG)libag.a

ENV = modules/environment/
ENV_INC = $(ENV)includes/
LIB_ENV = $(ENV)libenv.a

# Règles de compilation
all: lib $(NAME)

$(NAME): Makefile $(LIB_FT) $(LIB_AG) $(LIB_ENV) $(OBJ)
	@echo "$(CYAN)Compilation de $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(CFLAGSUP) $(OBJ) $(CLIB) -o $(NAME)

$(OBJ): $(INC)

lib:
	@echo "$(VERT)Compilation...$(RESET)"
	@make -C $(LIBFT) all
	@make -C $(LIBAG) LIBFT_INC=../libft/includes/ all
	@make -C $(ENV) LIBFT_INC=../libft/includes/ LIBAG_INC=../libag/includes/ all

clean: cleanproj
	@make -C $(LIBFT) clean
	@make -C $(LIBAG) clean
	@make -C $(ENV) clean

fclean: fcleanproj
	@make -C $(LIBFT) fclean
	@make -C $(LIBAG) fclean
	@make -C $(ENV) fclean

re: fclean all

cleanproj:
	@echo "$(ROUGEC)Suppression des fichiers objets de $(NAME)$(RESET)"
	@rm -f $(OBJ)

fcleanproj: cleanproj
	@echo "$(ROUGEC)Suppression de l'exécutable $(NAME)$(RESET)"
	@rm -f $(NAME)

# Règles pour la norme
norme: cleanproj
	@echo "$(MAGEN)Norme pour $(PROJECT)$(RESET)"
	@norminette includes/ src/

normeall: norme
	@make -C $(LIBFT) norme
	@make -C $(LIBAG) norme
	@make -C $(ENV) norme

# Règles pour la documentation
doxygen:
#	@echo "$(JAUNE)Pas de documentation pour $(PROJECT)$(RESET)"
	@echo "$(CYAN)Génération de la documentation de $(PROJECT)$(RESET)"
	@$(DOXYGEN) documentation/$(PROJECT).doxyconf > documentation/$(PROJECT).log
	@make -C $(LIBFT) doxygen $(DOXYGEN)
	@make -C $(LIBAG) doxygen $(DOXYGEN)
	@make -C $(ENV) doxygen $(DOXYGEN)

cleandoxy:
#	@echo "$(JAUNE)Pas de documentation pour $(PROJECT)$(RESET)"
	@echo "Suppression de la documentation de $(PROJECT)"
	@rm -rf documentation/html
	@rm -rf documentation/$(PROJECT).log
	@make -C $(LIBFT) cleandoxy
	@make -C $(LIBAG) cleandoxy
	@make -C $(ENV) cleandoxy

fcleanall: cleandoxy fclean

# Couleurs
RESET = \033[0m
BLANC = \033[37m
BLEU  = \033[34m
CYAN  = \033[36m
JAUNE = \033[33m
MAGEN = \033[35m
NOIR  = \033[30m
ROUGE = \033[31m
ROUGEC = \033[1;31m
VERT  = \033[32m

# VARIABLES
DOXYGEN = doxygen

.PHONY: all lib clean fclean re doxygen cleandoxy
