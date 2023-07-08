SRCS		=	ft_main.c \
				ft_copy_env.c \
				ft_signals.c \
				ft_free.c \
				parse/ft_parse.c \
				parse/ft_lists.c \
				parse/ft_quote.c \
				parse/ft_space.c \
				parse/ft_split_line.c \
				parse/ft_redirection.c \
				parse/ft_handle.c \
				parse/ft_pipe.c \
				lexer/ft_identify_token.c \
				lexer/ft_metacharacter.c \
				lexer/ft_quot_cleaner.c \
				lexer/ft_trim_quote.c \
				lexer/ft_type_counter.c

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