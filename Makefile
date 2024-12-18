NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Couleurs pour les messages
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[38;2;15;101;214m
RESET = \033[0m

LIBFT_DIR = includes/libft/
LIBFT_FILE = libft.a

PRINTF_DIR = includes/printf/
PRINTF_FILE = libftprintf.a

OBJ_PATH = obj/
PARSING_PATH = parsing/
CORE_PATH = core/
SRC_PATH = src/

SRC = main.c
CORE = core.c file_handle.c command_handle.c
PARSING = path.c commands.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
PARSINGS = $(addprefix $(PARSING_PATH), $(PARSING))
CORES = $(addprefix $(CORE_PATH), $(CORE))

OBJ_PARSING = $(PARSING:.c=.o)
OBJ_CORE = $(CORE:.c=.o)
OBJ_SRC = $(SRC:.c=.o)

OBJS_PARSING = $(addprefix $(OBJ_PATH), $(OBJ_PARSING))
OBJS_CORE = $(addprefix $(OBJ_PATH), $(OBJ_CORE))
OBJS_SRC = $(addprefix $(OBJ_PATH), $(OBJ_SRC))

LIBFT_LIB = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
PRINTF_LIB = $(addprefix $(PRINTF_DIR), $(PRINTF_FILE))

all: $(NAME)
	@echo ">>> $(BLUE)COMPILATION TERMINEE $(RESET)<<<"
	@echo "$(YELLOW)  _____ _____ _____  ________   __"
	@echo " |  __ \_   _|  __ \|  ____\ \ / /"
	@echo " | |__) || | | |__) | |__   \ V / "
	@echo " |  ___/ | | |  ___/|  __|   > <  "
	@echo " | |    _| |_| |    | |____ / . \ "
	@echo " |_|   |_____|_|    |______/_/ \_\\"

$(NAME): $(OBJS_SRC) $(OBJS_PARSING) $(OBJS_CORE) $(LIBFT_LIB) $(PRINTF_LIB)
	@$(CC) $(CFLAGS) $(OBJS_SRC) $(OBJS_PARSING) $(OBJS_CORE) $(LIBFT_LIB) $(PRINTF_LIB) -o $@

$(LIBFT_LIB):
	@make --no-print-directory -C $(LIBFT_DIR)

$(PRINTF_LIB):
	@make --no-print-directory -C $(PRINTF_DIR)

$(OBJ_PATH)%.o: $(PARSING_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(CORE_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo ">>> $(RED)SUPPRESSION DES FICHIERS .o $(RESET)<<<"
	@rm -rf $(OBJ_PATH)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@make --no-print-directory -C $(PRINTF_DIR) clean

fclean: clean
	@echo ">>> $(RED)SUPPRESSION DE L'EXECUTABLE $(RESET)<<<"
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@make --no-print-directory -C $(PRINTF_DIR) fclean

re: fclean all
	@echo "$(RESET)"

.PHONY: all clean fclean re

