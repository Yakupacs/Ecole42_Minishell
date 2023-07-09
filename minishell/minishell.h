#ifndef MINISHELL_H
# define MINISHELL_H
# include "parse/parse.h"
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

typedef struct s_global
{
	t_command		*list;
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
}	t_global;

void	loop(void);
int		continue_loop(t_command *temp);

void	ft_init_global(char **envp, int flag);
char	**copy_env(char **envp);

void	signal_exit(void);
void	ft_sig_handler(int sig);

int		ft_parse(void);

int		check_error(void);
int		error_check2(int flag, t_command *temp);
int		error_msg(int flag, t_command *temp);

void	freeliazer(t_command *temp);
void	ft_free_all(void);
void	ft_free_all2(void);

t_global	g_global;

#endif