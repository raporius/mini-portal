NAME = miniportal

SRCS = \
	srcs/utils_rapo.c \
	srcs/builtins/ft_pwd.c \
	srcs/builtins/ft_env.c \
	srcs/builtins/ft_export_utils.c \
	srcs/builtins/ft_export.c \
	srcs/env/envp_struct_funcs.c \
	srcs/env/init.c \
	srcs/parser/tokenizer.c  \
	srcs/parser/tokenizer_utils.c

OBJS = $(SRCS:.c=.o)
LIBFT = ./libft-portal/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincludes -Ilibft-portal/includes
LDFLAGS = -Llibft-portal -lft

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libft-portal

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C ./libft-portal

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft-portal

re: fclean all

.PHONY: all clean fclean re