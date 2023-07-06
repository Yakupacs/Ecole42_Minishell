SRCS		=	ft_main.c ft_copy_env.c ft_signals.c ft_free.c ft_parse.c

LIBFT		=	libft/libft.a

OBJS		= 	$(SRCS:.c=.o)

NAME		=	minishell

LDFLAGS		=	-lreadline

CC			=	gcc -g

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -rf

all:		$(NAME) 

$(NAME):		$(OBJS) $(LIBFT)
				@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(LDFLAGS) -o $(NAME)
				@printf "\033[1;32mMinishell compiled.\033[0m\n"

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@make clean -C ./libft

$(LIBFT):
				@make -C ./libft
				@make bonus -C ./libft

fclean:
				@$(RM) $(OBJS) $(NAME)
				@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re