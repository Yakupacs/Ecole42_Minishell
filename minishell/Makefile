SRCS		=	main.c copy_env.c

LIBFT		=	libft/libft.a

OBJS		= 	$(SRCS:.c=.o)

NAME		=	minishell

CC			=	gcc -g

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -rf

all:		$(NAME) 


$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -lreadline -o $(NAME)

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