/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:07:00 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/20 01:50:57 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_type_counter{
	int	dollar;
	int	rdr;
	int	heredoc;
	int	word;
	int	pipe;
}					t_type_counter;

typedef struct s_command {
	char				*arg;
	enum e_character	type;
	struct s_command	*next;
}					t_command;

/* LEXER */

int			ft_lexer(void);
int			tokenizer(t_command **tmp_line);

void		split_line(char *s, t_command *line);
void		split_line2(int st, int len, char *line, t_command *tmp_line);

int			check_quote(char *line);
void		check_space(char *line, t_command **tmp_line);

void		check_redirection(t_command **tmp_line);
void		check_pipe(t_command **prompt);

t_command	*p_lstlast(t_command *lst);
void		p_lstadd_back(t_command **lst, t_command *new);
t_command	*p_lstnew(int type, char *line);
int			p_lstsize(t_command *lst);

int			is_space(char c);
int			is_quotation(char *s);
int			is_pipe(char *s);
int			is_redirection(char *line);

int			handle_character(t_command **list, int (*checker)(char *));
void		*append_list(t_command **prompt, int st, int len);
t_command	*create_front(int st, int len, t_command **list, t_command *tmp);

int			identify_token(t_command **token);
int			initialize_metacharacter(t_command *node);
int			is_dollar(char *s);

int			calculate_new_arg_len(char *s);
char		*trim_quot2(char *s, char *new);
char		*trim_quot(char *s);
int			contains_quot(char *s);

void		type_counter(t_command	**token);
void		quot_cleaner(t_command **token);

/* PARSER */

void		ft_dollars(void);
int			quote_parse(char *str);
void		dollar_parse(char *str);
int			special_dollar(int i, char *prev_arg);
void		ft_parse_variables(void);
char		*ft_strjoin_char(char *s1, char c);

char		*ft_find_env(char *arg);
char		*ft_find_env2(char *line, char *arg, char *ret, int j);
char		*line_connect(char *arg);
int			ft_equal_finder(char *line, char *envp);

void		ft_heredoc(void);
void		ft_heredoc_start(void);
void		ft_heredoc_readline(int i);
void		init_pipe(void);

#endif