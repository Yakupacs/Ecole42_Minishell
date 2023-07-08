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
	char				*arg;
	enum e_character	type;
	struct s_arg		*next;
}					t_arg;

int		ft_parse(void);
int		tokenizer(t_arg **tmp_line);

void	split_line(char *s, t_arg *line);
void	split_line2(int st, int len, char *line, t_arg *tmp_line);

int		check_quote(char *line);
void	check_space(char *line, t_arg **tmp_line);

void	check_redirection(t_arg **tmp_line);
void	check_pipe(t_arg **prompt);

t_arg	*p_lstlast(t_arg *lst);
void	p_lstadd_back(t_arg **lst, t_arg *new);
t_arg	*p_lstnew(int type, char *line);
int		p_lstsize(t_arg *lst);

int 	is_space(char c);
int		is_quotation(char *s);
int		is_pipe(char *s);
int		is_redirection(char *line);

int		handle_character(t_arg **list, int (*checker)(char *));
void	*append_list(t_arg **prompt, int st, int len);
t_arg	*create_front(int st, int len, t_arg **list, t_arg *tmp);

int		identify_token(t_arg **prompt);
int		initialize_metacharacter(t_arg *node);
int		is_dollar(char *s);

int		check_quotation(char *s);
int		calculate_new_arg_len(char *s);
char	*trim_quot2(char *s, char *new);
char	*trim_quot(char *s);
int		contains_quot(char *s);

void	type_counter(t_arg	**prompt);
void	quot_cleaner(t_arg **prompt);

#endif