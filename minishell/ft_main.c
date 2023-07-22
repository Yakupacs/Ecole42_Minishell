/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:04:55 by yacis             #+#    #+#             */
/*   Updated: 2023/07/22 11:09:15 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(char **envp)
{
	int		i;
	char	**copy_env;

	i = 0;
	while (envp[i])
		i++;
	copy_env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		copy_env[i] = ft_strdup(envp[i]);
		i++;
	}
	copy_env[i] = NULL;
	return (copy_env);
}

void	ft_init_global(char **envp, int flag)
{
	if (flag)
	{
		g_global.ex_path = copy_env(envp);
		g_global.envp = copy_env(envp);
	}
	g_global.signal_status = 0;
	g_global.list = NULL;
	g_global.command = NULL;
	g_global.redirection = NULL;
	g_global.count_type = NULL;
	g_global.heredoc = NULL;
	g_global.line = NULL;
	g_global.sig_flag = 0;
	g_global.error_flag = 0;
	g_global.here_fd = 0;
	g_global.heredoc_flag = 0;
	g_global.dollar_flag = 0;
	g_global.sighandler_flag = 0;
	g_global.execute_signal_flag = 0;
}

int	continue_loop(t_command *cpy_g_global_list)
{
	if (check_error() == -1)
	{
		cpy_g_global_list = NULL;
		return (-1);
	}
	if (g_global.count_type->dollar > 0)
		ft_dollars();
	if (g_global.count_type->heredoc > 0)
		ft_heredoc();
	if (ft_strcmp(g_global.list->arg, "exit"))
	{
		ft_exit(cpy_g_global_list);
		return (-1);
	}
	if (initialize_pipe() == -1)
		execute();
	return (0);
}

void	loop(void)
{
	t_command	*cpy_g_global_list;

	while (1)
	{
		ft_init_global(g_global.envp, 0);
		g_global.line = readline("minishell$ ");
		if (g_global.sig_flag == 1)
		{
			free(g_global.line);
			continue ;
		}
		if (!g_global.line)
			signal_exit();
		ft_lexer();
		cpy_g_global_list = g_global.list;
		add_history(g_global.line);
		free(g_global.line);
		continue_loop(cpy_g_global_list);
		freeliazer(cpy_g_global_list);
	}
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, ft_sighandler_quit);
	g_global.exit_status = 1;
	ft_init_global(envp, 1);
	loop();
	return (0);
}
