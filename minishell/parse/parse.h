#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

enum e_character {
	WORD,
	INPUT_RDR,
	OUTPUT_RDR,
	DOUBLE_OUTPUT_RDR,
	DOUBLE_INPUT_RDR,
	PIPE,
	DOLLAR
};

enum e_loc_quot {
	none,
	head_end,
	midle
};

typedef struct s_type_counter{
	int	dollar;
	int	rdr;
	int	heredoc;
	int	word;
	int	pipe;
}					t_type_counter;

typedef struct s_arg {
	char				*content;
    enum e_character	type;
    struct s_arg		*next;
}					t_arg;

int ft_parse(void);
int tokenizer(t_arg **tmp_line);

void	split_line(char *s, t_arg *line);
void	split_line2(int st, int len, char *line, t_arg *tmp_line);

void	check_space(char *line, t_arg **tmp_line);

int    check_quote(char *line);

t_arg	*p_lstlast(t_arg *lst);
void	p_lstadd_back(t_arg **lst, t_arg *new);
t_arg	*p_lstnew(int type, char *line);

int is_space(char c);
int	is_quotation(char *s);

#endif