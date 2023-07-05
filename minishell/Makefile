SRCS =

LIBFT =

OBJS = 

NAME	=	minishell

CC		=	gcc -g

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)

clean:	
		@$(RM) $(OBJS)
		@make clean -C ./libft

$(LIBFT):
		@make -C ./libft
		@make bonus -C ./libft
	
fclean:
		@$(RM) $(OBJS) $(NAME)
		@make fclean -C libft

re:		fclean all

.PHONY:	all clean fclean re