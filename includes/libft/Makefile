CC = cc

OBJ_PATH = obj/

SRC = ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memchr.c ft_memcpy.c ft_memset.c ft_strlcat.c ft_strlen.c ft_strnstr.c \
	ft_tolower.c ft_atoi.c  ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcmp.c ft_memmove.c ft_strchr.c ft_strlcpy.c \
	ft_strncmp.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strdup.c ft_substr.c

OBJ = $(SRC:.c=.o)
NAME = libft.a
CFLAGS = -Werror -Wextra -Wall

OBJS_SRC = $(addprefix $(OBJ_PATH), $(OBJ))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS_SRC)
	@ar -rcs $(NAME) $(OBJS_SRC) -o $@

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

clean : 
	@rm -f $(OBJ) $(B_OBJ)

fclean : clean
	rm -f $(NAME)

bonus : $(OBJ) $(B_OBJ)
	ar -rcs $(NAME) (BONUS) $(B_OBJ)

re : fclean all
