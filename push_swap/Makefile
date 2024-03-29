# Chemins de base du projet #######################################################################
SRC_DIR = ./src/
INCLUDE = ./includes/
LIBFT_PATH = ./libft
PRINTF_PATH = ./printf
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

RM = rm -f

# Options pour l'affichage de messages ############################################################

GREEN=\033[0;32m
RESET=\033[0m

# Compilateur et options de compilations ##########################################################

CC = cc
FLAGS = -Wall -Wextra -Werror -g3 -g
LIBS = $(LIBFT) $(PRINTF)
HEADER = -I$(INCLUDE) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

# Fichiers sources et cibles ######################################################################

SRC = main.c \
		parsing/errors.c \
		parsing/lists.c \
		parsing/parsing.c \
		parsing/ft_free.c \
		parsing/parsing_utils.c \
		operations/swap.c \
		operations/rotate.c \
		operations/rev_rotate.c \
		operations/push.c \
		sorting/sort.c \
		sorting/algorithm.c \
		sorting/algo_utils_1.c \
		sorting/algo_utils_2.c \
		sorting/algo_utils_3.c \
		sorting/cost_functions.c \
		sorting/push_back.c

SRC_PATH = ./src

OBJS = $(addprefix $(SRC_PATH)/, $(SRC:.c=.o))
NAME = push_swap

# Regle par defaut ################################################################################

all: $(NAME)

# Liaison des Objets pour creer l'executable #######################################################

$(NAME): $(LIBS) $(OBJS)
	@$(CC) $(HEADER) $(OBJS) $(LIBS) $(FLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation globale reussie !$(RESET)"

# Compilation des fichiers sources en objets #######################################################
%.o : %.c
	@$(CC) -c $(FLAGS) -I$(INCLUDE)  $< -o $@

# Compilation des librairies externes #############################################################

$(LIBFT):
	@make -C $(LIBFT_PATH) -s
	@echo "$(GREEN)Compilation libft reussie !$(RESET)"

$(PRINTF):
	@make -C $(PRINTF_PATH) -s
	@echo "$(GREEN)Compilation printf reussie !$(RESET)"

# Nettoyage ########################################################################################

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean

re: fclean all

# Directives Phony pour eviter les conflits avec fichiers de meme nom ###############################

.PHONY: all clean fclean re