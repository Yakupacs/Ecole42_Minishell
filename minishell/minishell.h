#ifndef MINISHELL_H
# define MINISHELL_H
# include "parse.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <dirent.h>
# include <stdarg.h>
# include <string.h>

typedef struct s_data
{
	t_arg			*list;
	t_type_counter	*count_type;
	char			*line;
	char			**envp;
	char			**ex_path;
	char			**heredoc;
	char			**command;
	char			**redirection;
	int				signal_status;
	int				**all_pipe_fd;
	int				fd;
	int				pipe_c;
	int				*pipe_id;
	int				exit_status;
	char			*here_line;
	int				*here_fd;
	int				*exec_fd;
	int				here_count;
	char			*main_here_line;
	int				main_here_size;
	char			**dollars;
	char			**dollar_line;
	int				sig_flag;
	int				error_flag;
}	t_data;

void    loop(void);
int		after_loop(t_arg *temp);

void	ft_struct_initilaize(char **envp, int flag);
char	**copy_env(char **envp);

void	signal_exit(void);
void	ft_sig_handler(int sig);

int		ft_parse(void);

void	freeliazer(t_arg *temp);
void	ft_free_all(void);
void	ft_free_all2(void);

t_data  g_data;

#endif