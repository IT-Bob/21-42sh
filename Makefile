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
CPPFLAGS =	-I $(INC_PATH) -I $(LIB_INC) -I $(LIBAG_INC) -I $(ENV_INC)  \
			-I $(LINE_INC) -I $(CMP_INC) -I $(LIBMT_INC) -I $(ERROR_INC) -I $(PARSER_INC) -I $(HIST_INC) -I $(EXEC_INC)

CLIB =	-L $(LINE) -llinput -L $(CMP) -lcomplete -L $(HIST) -lstory -L $(ENV) -lenv \
		-L $(PARSER) -lparser -L $(LIBAG) -lag -L $(LIBMT) -lmt -L $(EXEC) -lexec \
		-L $(ERROR) -lerror -L $(LIBFT) -lft -ltermcap \

# Fichiers d'en-tête
INC_PATH = includes/
INC_FILE = sh.h
INC = $(addprefix $(INC_PATH), $(INC_FILE))

# Fichiers sources
SRC_PATH = src/
SRC_FILE = builtin.c execute.c history.c quotes.c sh.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

# Fichiers des bibliothèques
LIBFT = modules/libft/
LIB_INC = $(LIBFT)includes/
LIB_FT = $(LIBFT)libft.a

LIBAG = modules/libag/
LIBAG_INC = $(LIBAG)includes/
LIB_AG = $(LIBAG)libag.a

LIBMT = modules/libmt/
LIBMT_INC = $(LIBMT)includes/
LIBMT_MT = $(LIBMT)libmt.a

ERROR = modules/error/
ERROR_INC = $(ERROR)/includes/
LIB_ERROR = $(ERROR)/liberror.a

ENV = modules/environment/
ENV_INC = $(ENV)includes/
LIB_ENV = $(ENV)libenv.a

LINE = modules/line_input/
LINE_INC = $(LINE)includes/
LIB_LINE = $(LINE)liblinput.a

CMP = modules/completion/
CMP_INC = $(CMP)includes/
LIB_CMP = $(CMP)libcomplete.a

HIST = modules/history/
HIST_INC = $(HIST)includes/
LIB_HIST = $(HIST)libstory.a

PARSER = modules/parser/
PARSER_INC = $(PARSER)/includes/
LIB_PARSER = $(PARSER)libparser.a

EXEC = modules/execution/
EXEC_INC = $(EXEC)/includes/
LIB_EXEC = $(EXEC)libexec.a

# Règles de compilation
all: lib $(NAME)

$(NAME): Makefile $(LIB_FT) $(LIB_AG) $(LIB_MT) $(LIB_ERROR) $(LIB_ENV) $(LIB_HIST) \
$(LIB_LINE) $(LIB_CMP) $(LIB_PARSER) $(LIB_EXEC) $(OBJ)

	@echo "$(CYAN)Compilation de $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(CFLAGSUP) $(OBJ) $(CLIB) -o $(NAME)

$(OBJ): $(INC)

lib:
	@echo "$(VERT)Compilation...$(RESET)"
	@make -C $(LIBFT) all
	@make -C $(LIBAG) LIBFT_INC=../libft/includes/ all
	@make -C $(LIBMT) LIBFT_INC=../libft/includes/ all
	@make -C $(ERROR) LIBFT_INC=../libft/includes/ all
	@make -C $(ENV) LIBFT_INC=../libft/includes/ LIBAG_INC=../libag/includes/ all
	@make -C $(CMP) LIBFT_INC=../libft/includes/ LIBAG_INC=../libag/includes/ all
	@make -C $(HIST) LIBFT_INC=../libft/includes/ LIBAG_INC=../libag/includes/ all
	@make -C $(PARSER) LIBFT_INC=../libft/includes/ LIBMT_INC=../libmt/includes/ \
	ERROR_INC=../error/includes EXEC_INC=../execution/includes all
	@make -C $(EXEC) LIBFT_INC=../libft/includes PARSER_INC=../parser/includes \
	LIBMT_INC=../libmt/includes ERROR_INC=../error/includes all
	@make -C $(LINE) LIBFT_INC=../libft/includes/ LIBAG_INC=../libag/includes/ \
	ENV_INC=../environment/includes CMP_INC=../completion/includes all

clean: cleanproj
	@make -C $(LIBFT) clean
	@make -C $(LIBAG) clean
	@make -C $(LIBMT) clean
	@make -C $(ERROR) clean
	@make -C $(ENV) clean
	@make -C $(CMP) clean
	@make -C $(HIST) clean
	@make -C $(PARSER) clean
	@make -C $(EXEC) clean
	@make -C $(LINE) clean

fclean: fcleanproj
	@make -C $(LIBFT) fclean
	@make -C $(LIBAG) fclean
	@make -C $(LIBMT) fclean
	@make -C $(ERROR) fclean
	@make -C $(ENV) fclean
	@make -C $(CMP) fclean
	@make -C $(HIST) fclean
	@make -C $(PARSER) fclean
	@make -C $(EXEC) fclean
	@make -C $(LINE) fclean

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
	@make -C $(LIBMT) norme
	@make -C $(ERROR) norme
	@make -C $(ENV) norme
	@make -C $(CMP) norme
	@make -C $(HIST) norme
	@make -C $(PARSER) norme
	@make -C $(EXEC) norme
	@make -C $(LINE) norme

# Règles pour la documentation
doxygen:
	@echo "$(JAUNE)Pas de documentation pour $(PROJECT)$(RESET)"
#	@echo "$(CYAN)Génération de la documentation de $(PROJECT)$(RESET)"
#	@$(DOXYGEN) documentation/$(PROJECT).doxyconf > documentation/$(PROJECT).log
	@make -C $(LIBFT) doxygen $(DOXYGEN)
	@make -C $(LIBAG) doxygen $(DOXYGEN)
	@make -C $(ENV) doxygen $(DOXYGEN)
	@make -C $(CMP) doxygen $(DOXYGEN)
	@make -C $(HIST) doxygen $(DOXYGEN)
	@make -C $(LINE) doxygen $(DOXYGEN)

cleandoxy:
	@echo "$(JAUNE)Pas de documentation pour $(PROJECT)$(RESET)"
#	@echo "Suppression de la documentation de $(PROJECT)"
#	@rm -rf documentation/html
#	@rm -rf documentation/$(PROJECT).log
	@make -C $(LIBFT) cleandoxy
	@make -C $(LIBAG) cleandoxy
	@make -C $(ENV) cleandoxy
	@make -C $(CMP) cleandoxy
	@make -C $(HIST) cleandoxy
	@make -C $(LINE) cleandoxy

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
