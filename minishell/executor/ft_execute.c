/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:36 by yacis             #+#    #+#             */
/*   Updated: 2023/07/18 15:12:57 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_dollar_exit(void)
{
	if (g_global.dollar_flag)
		exit(0);
	else
		ft_execve();
}

void	check_way(void)
{
	int		status;

	status = 0;
	if (g_global.count_type->heredoc)
	{
		dup2(g_global.here_fd[0], STDIN_FILENO);
		close(g_global.here_fd[0]);
	}
	if (g_global.redirection != NULL)
		exec_redir(status);
	if (ft_strcmp(g_global.command[0], "export"))
	{
		if (g_global.command[1] == NULL)
			ft_export_path();
		else
			ft_export();
		exit(0);
	}
	else if (ft_strcmp(g_global.command[0], "echo"))
	{
		ft_echo();
		exit(0);
	}
	else if (g_global.command != NULL)
		check_dollar_exit();
}

/* WIFEXITED child process sonlanırsa 1 döner. */
/* WEXITSTATUS child process'in exit değerini alır. */

void	execute(void)
{
	int	status;
	int	i;

	i = 0;
	g_global.sighandler_flag = 1;
	ft_command_line();
	if (builtin() == -1)
		status = fork();
	else
		return ;
	g_global.execute_signal_flag = 1;
	if (status == 0)
		check_way();
	else
		waitpid(status, &g_global.exit_status, 0);
	g_global.execute_signal_flag = 0;
	if (WIFEXITED(g_global.exit_status) && i == 0)
	{
		g_global.exit_status = WEXITSTATUS(g_global.exit_status);
		i++;
	}
}