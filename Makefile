NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Couleurs pour les messages
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[38;2;15;101;214m
RESET = \033[0m

LIBFT_DIR = include/libft/
PRINTF = $(LIBFT_DIR)/libft.a

OBJ_PATH = obj/
PARSING_PATH = parsing/
UTIL_PATH = utils/
SRC_PATH = src/

SRC = main.c
# UTIL = push_rotate.c
# PARSING = parsing.c ft_utils_node_remains.c ft_utils_node.c parsing2.c gen_utils.c ft_itoa.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
# PARSINGS = $(addprefix $(PARSING_PATH), $(PARSING))
# UTILS = $(addprefix $(UTIL_PATH), $(UTIL))

# OBJ = $(PARSING:.c=.o)
# OBJ_UTIL = $(UTIL:.c=.o)
OBJ_SRC = $(SRC:.c=.o)
# OBJ_SORT = $(SORT:.c=.o)

# OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
# OBJS_UTIL = $(addprefix $(OBJ_PATH), $(OBJ_UTIL))
OBJS_SRC = $(addprefix $(OBJ_PATH), $(OBJ_SRC))
# OBJS_SORT = $(addprefix $(OBJ_PATH), $(OBJ_SORT))

$(libft):
	@make --no-print-directory -C $(LIBFT_DIR)

all: $(NAME)
	@echo ">>> $(BLUE)COMPILATION TERMINEE $(RESET)<<<"
	@echo "$(YELLOW)  _____ _____ _____  ________   __"
	@echo " |  __ \_   _|  __ \|  ____\ \ / /"
	@echo " | |__) || | | |__) | |__   \ V / "
	@echo " |  ___/ | | |  ___/|  __|   > <  "
	@echo " | |    _| |_| |    | |____ / . \ "
	@echo " |_|   |_____|_|    |______/_/ \_\\"

$(NAME): $(OBJS_SRC)
	@$(CC) $(CFLAGS) $(OBJS_SRC) -o $@

# $(OBJ_PATH)%.o: $(PARSING_PATH)%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
#
# $(OBJ_PATH)%.o: $(UTIL_PATH)%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo ">>> $(RED)SUPPRESSION DES FICHIERS .o $(RESET)<<<"
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)"
	@echo "$(RESET)"

fclean: clean
	@echo ">>> $(RED)SUPPRESSION DE L'EXECUTABLE $(RESET)<<<"
	@echo "\n"
	@rm -f $(NAME)
	
re: fclean all
	@echo "$(RESET)"

.PHONY: all clean fclean re
