SRCS		=	ft_main.c \
				ft_global.c \
				ft_envp.c \
				ft_signals.c \
				ft_free.c \
				ft_error.c \
				ft_exit.c \
				lexer/ft_lexer.c \
				lexer/ft_lists.c \
				lexer/ft_check_quote.c \
				lexer/ft_check_space.c \
				lexer/ft_split_line.c \
				lexer/ft_check_redirection.c \
				lexer/ft_handle.c \
				lexer/ft_check_pipe.c \
				lexer/ft_identify_token.c \
				lexer/ft_metacharacter.c \
				lexer/ft_quot_cleaner.c \
				lexer/ft_trim_quote.c \
				lexer/ft_type_counter.c \
				parse/ft_dollars.c \
				parse/ft_parse_variables.c \
				parse/ft_find_env.c \
				parse/ft_heredoc.c \
				parse/ft_strcmp.c \

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