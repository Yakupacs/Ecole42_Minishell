/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:05:01 by yacis             #+#    #+#             */
/*   Updated: 2023/07/15 03:24:04 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "parser/parse.h"
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
int		continue_loop(t_command *cpy_g_global_list);
void	exec_shell(int status);

void	ft_init_global(char **envp, int flag);
char	**copy_env(char **envp);

void	ft_sig_handler(int sig);

int		ft_lexer(void);

int		check_error(void);
int		error_check2(int flag, t_command *temp);
int		error_msg(int flag, t_command *temp);

void	freeliazer(t_command *temp);
void	ft_free_all(void);
void	ft_free_all2(void);

void	ft_exit(t_command *data);
void	ft_exit2(t_command *temp);
int		ft_check_digit(char *str);
void	signal_exit(void);

int		ft_strcmp(char *s1, char *s2);

int		initialize_pipe(void);
int		pipe_counter(void);
void	create_pipes(void);

void	initialize_fork(void);
void	initialize_fork2(void);
void	pipe_free(void);
void	set_file_descriptor(int id);

void	ft_command_line(void);
void	ft_command_redirection_len(t_command *temp, int i, int j);
void	ft_command_line2(t_command *temp, int i, int j);

void	ft_free_command_redirection(void);
void	close_fd(int id);
void	close_fd2(int k, int i);
void	close_fd3(int k, int i, int id);

void	execute(void);
void	check_way(void);
int		builtin(void);

void	ft_echo(void);
int		ft_echo_param_checker(char *str);

void	exec_redir(int status);
void	exec_redir2(int status, char **redir, int i);

void	ft_execve(void);
int		control_bin(void);
int		control_bin2(char *path, int j);

void	ft_cd(void);
void	ft_pwd_changer(void);
void	ft_oldpwd_changer(void);
void	ft_pwd(void);

void	ft_unset(void);
int		ft_path_founder(char **envp, char *name);
int		ft_path_counter(char *name);
int		env_founder(char *envp, char *name, int len);

void	ft_export(void);
void	ft_export2(int line, int line_exp, int j);
int		ft_env_controller(int j);
void	*ft_export_path(void);
int		name_error(int j);

void	ft_env(void);
void	upenv(char **envp, int j, int flag);
int		equal_counter(char *name);
void	ft_delenv(char **envp, int j, int flag);
void	ft_delenv2(char **new_envp, int flag);
void	ft_addenv(char **envp, int j, int flag);
int		env_counter(char **envp);

t_global	g_global;

#endif