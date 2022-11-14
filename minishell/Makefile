RESET	=	\033[0m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RED		=	\033[31m

NAME = minishell 

SRCS = main.c echo.c pwd.c env_get.c env_create.c export.c

OBJS = $(SRCS:.c=.o)

MFLAGS = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -lreadline -I./libft

all: $(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./libft

$(NAME):
	@echo "$(GREEN)Compiling... [$(NAME)]"
	@$(CC) $(CFLAGS) $(SRCS) $(MFLAGS) -o $(NAME)
	@echo "$(GREEN)Finished. [$(NAME)]"

clean:
	make fclean -C ./libft
	@rm -rf *.o

fclean: clean
	make clean -C ./libft
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re