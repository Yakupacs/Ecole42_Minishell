SRCS		=	ft_main.c \
				ft_envp.c \
				ft_signals.c \
				ft_free.c \
				ft_error.c \
				lexer/ft_lexer.c \
				lexer/ft_lists.c \
				lexer/ft_quote.c \
				lexer/ft_space.c \
				lexer/ft_split_line.c \
				lexer/ft_redirection.c \
				lexer/ft_handle.c \
				lexer/ft_pipe.c \
				parse/ft_identify_token.c \
				parse/ft_metacharacter.c \
				parse/ft_quot_cleaner.c \
				parse/ft_trim_quote.c \
				parse/ft_type_counter.c

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