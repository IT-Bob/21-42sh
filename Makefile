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
			-I $(LINE_INC) -I $(CMP_INC) -I $(LIBMT_INC) -I $(ERROR_INC) -I $(PARSER_INC) -I $(HIST_INC) -I $(EXEC_INC) -I $(BUILT_INC) -I $(HERE_INC)

CLIB =	-L $(EXEC) -lexec -L $(HEREDOC) -lheredoc -L $(LINE) -llinput -L $(CMP) -lcomplete -L $(PARSER) -lparser\
		-L $(BUILT) -luiltins -L $(HIST) -lstory -L $(ENV) -lenv -L $(ERROR) -lerror\
		-L $(LIBMT) -lmt -L $(LIBAG) -lag -L $(LIBFT) -lft -ltermcap

# Fichiers d'en-tête
INC_PATH = includes/
INC_FILE = sh.h
INC = $(addprefix $(INC_PATH), $(INC_FILE))
SH = SH_INC=../../$(INC_PATH)

# Fichiers sources
SRC_PATH = src/
SRC_FILE = builtin.c env.c history.c line.c local.c quotes.c sh.c signal.c tools.c ft_expand_exclam.c ft_expand_dollar.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

# Fichiers des bibliothèques
LIBFT = libft/
LIB_INC = $(LIBFT)includes/
LIB_FT = $(LIBFT)libft.a
FT = LIBFT_INC=../../libft/includes

LIBAG = modules/libag/
LIBAG_INC = $(LIBAG)includes/
LIB_AG = $(LIBAG)libag.a
AG = LIBAG_INC=../libag/includes

LIBMT = modules/libmt/
LIBMT_INC = $(LIBMT)includes/
LIBMT_MT = $(LIBMT)libmt.a
MT = LIBMT_INC=../libmt/includes

ERROR = modules/error/
ERROR_INC = $(ERROR)/includes/
LIB_ERROR = $(ERROR)/liberror.a
ERR = ERROR_INC=../error/includes

ENV = modules/environment/
ENV_INC = $(ENV)includes/
LIB_ENV = $(ENV)libenv.a
ENVI = ENV_INC=../environment/includes

LINE = modules/line_input/
LINE_INC = $(LINE)includes/
LIB_LINE = $(LINE)liblinput.a
LIN = LINE_INC=../line_input/includes

CMP = modules/completion/
CMP_INC = $(CMP)includes/
LIB_CMP = $(CMP)libcomplete.a
COMP = CMP_INC=../completion/includes

HIST = modules/history/
HIST_INC = $(HIST)includes/
LIB_HIST = $(HIST)libstory.a
HST = HIST_INC=../history/includes

PARSER = modules/parser/
PARSER_INC = $(PARSER)/includes/
LIB_PARSER = $(PARSER)libparser.a
PARS = PARSER_INC=../parser/includes

EXEC = modules/execution/
EXEC_INC = $(EXEC)/includes/
LIB_EXEC = $(EXEC)libexec.a
XC = EXEC_INC=../execution/includes

BUILT = modules/builtins/
BUILT_INC = $(BUILT)includes/
LIB_BUILT = $(BUILT)libuiltins.a
BLT = BUILT_INC=../builtins/includes

HEREDOC = modules/heredocs/
HERE_INC = $(HEREDOC)includes/
LIB_HERE = $(HEREDOC)libheredoc.a
HRD = HERE_INC=../heredocs/includes

# Règles de compilation
all: lib $(NAME)

$(NAME): Makefile $(LIB_FT) $(LIB_AG) $(LIB_MT) $(LIB_ERROR) $(LIB_ENV) $(LIB_HIST) \
$(LIB_LINE) $(LIB_CMP) $(LIB_PARSER) $(LIB_EXEC) $(LIB_BUILT) $(LIB_HERE) $(OBJ)

	@echo "$(CYAN)Compilation de $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(CFLAGSUP) $(OBJ) $(CLIB) -o $(NAME)

$(OBJ): $(INC)

lib:
	@echo "$(VERT)Compilation...$(RESET)"
	@make -C $(LIBFT) all
	@make -C $(LIBAG) $(FT) all
	@make -C $(LIBMT) $(FT) all
	@make -C $(ERROR) $(FT) all
	@make -C $(ENV) $(FT) $(AG) $(ERR) all
	@make -C $(CMP) $(FT) $(AG) $(ERR) all
	@make -C $(HIST) $(FT) $(AG) $(ERR) all
	@make -C $(PARSER) $(FT) $(MT) $(ERR) all
	@make -C $(EXEC) $(AG) $(FT) $(PARS) $(MT) $(ERR) $(ENVI) $(BLT) $(HST) all
	@make -C $(LINE) $(FT) $(AG) $(ENVI) $(COMP) $(ERR) $(HRD) all
	@make -C $(HEREDOC) $(FT) $(AG) $(HST) $(ENVI) $(LIN) $(COMP) $(ERR) all
	@make -C $(BUILT) $(FT) $(AG) $(ENVI) $(HST) $(ERR) $(XC) $(PARS) $(MT) $(SH) all

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
	@make -C $(BUILT) clean
	@make -C $(HEREDOC) clean

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
	@make -C $(BUILT) fclean
	@make -C $(HEREDOC) fclean

re: fclean all

cleanproj:
	@echo "$(ROUGEC)Suppression des fichiers objets de $(NAME)$(RESET)"
	@rm -f $(OBJ)

fcleanproj: cleanproj
	@echo "$(ROUGEC)Suppression de l'exécutable $(NAME)$(RESET)"
	@rm -f $(NAME)

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

.PHONY: all lib clean fclean re doxygen cleandoxy
