#ifndef LEXER_H
# define LEXER_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_input {
	int		double_quotes;
	int		single_quotes;
	char	**args;
	char	**envs;
	char	*line;
	int		args_size;
	int		dollar_size;
	int		env_size;
	int		i;
	int		j;
	int		k;
	int		l;
	int		a;
	int		b;
}				t_input;

int		count_double_quotes(char *line);
int		count_single_quotes(char *line);