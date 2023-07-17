/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:41 by yacis             #+#    #+#             */
/*   Updated: 2023/07/17 02:00:49 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_file_descriptor(int id)
{
	if (id == 0)
	{
		dup2(g_global.all_pipe_fd[id][1], 1);
		close_fd(id);
		check_way();
	}
	else if (id == g_global.pipe_c)
	{
		dup2(g_global.all_pipe_fd[id - 1][0], 0);
		close_fd(id);
		check_way();
	}
	else
	{
		dup2(g_global.all_pipe_fd[id - 1][0], 0);
		dup2(g_global.all_pipe_fd[id][1], 1);
		close_fd(id);
		check_way();
	}
}

void	pipe_free(void)
{
	int	i;

	i = 0;
	while (i < g_global.pipe_c)
	{
		free(g_global.all_pipe_fd[i]);
		i++;
	}
	free(g_global.all_pipe_fd);
}

void	initialize_fork2(void)
{
	int	k;
	int	j;
	int	i;

	k = -1;
	j = -1;
	i = 0;
	while (++k != g_global.pipe_c)
	{
		while (++j != 2)
			close(g_global.all_pipe_fd[k][j]);
		j = -1;
	}
	while (i <= g_global.pipe_c)
	{
		waitpid(g_global.pipe_id[i], &g_global.exit_status, 0);
		i++;
		if (WIFEXITED(g_global.exit_status))
			g_global.exit_status = WEXITSTATUS(g_global.exit_status);
	}
	free(g_global.pipe_id);
}

void	initialize_fork(void)
{
	int	i;

	i = 0;
	g_global.pipe_id = malloc(sizeof(int) * (g_global.pipe_c + 1));
	while (i <= g_global.pipe_c)
	{
		if (i != 0 && g_global.command)
			ft_free_command_redirection();
		ft_command_line();
		g_global.pipe_id[i] = fork();
		if (g_global.pipe_id[i] == 0)
			set_file_descriptor(i);
		else
			i++;
	}
	initialize_fork2();
	pipe_free();
}
