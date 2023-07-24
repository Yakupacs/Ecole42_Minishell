/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:28 by yacis             #+#    #+#             */
/*   Updated: 2023/07/24 09:24:48 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_fd3(int k, int i, int id)
{
	while (++k < g_global.pipe_c)
	{
		while (++i != 2)
			if (!(((i == 0 && k == id - 1)) || (i == 1 && k == id)))
				close(g_global.all_pipe_fd[k][i]);
		i = -1;
	}
}

void	close_fd2(int k, int i)
{
	while (++k < g_global.pipe_c)
	{
		while (++i != 2)
			if (!(i == 0 && (k == g_global.pipe_c - 1)))
				close(g_global.all_pipe_fd[k][i]);
		i = -1;
	}
}

/*
	close(g_global.all_pipe_fd[0][0])
	close(g_global.all_pipe_fd[1][0])
	close(g_global.all_pipe_fd[1][1])
*/

void	close_fd(int id)
{
	int	i;
	int	k;

	k = -1;
	i = -1;
	if (id == 0)
	{
		while (++k < g_global.pipe_c)
		{
			while (++i != 2)
				if (!(i == 1 && k == 0))
					close(g_global.all_pipe_fd[k][i]);
			i = -1;
		}
	}
	else if (id == g_global.pipe_c)
		close_fd2(k, i);
	else
		close_fd3(k, i, id);
}

void	ft_free_command_redirection(void)
{
	int	i;

	i = -1;
	while (g_global.command[++i])
		free(g_global.command[i]);
	free(g_global.command);
	i = -1;
	if (g_global.redirection)
	{
		while (g_global.redirection[++i])
			free(g_global.redirection[i]);
		free(g_global.redirection);
	}
	g_global.command = NULL;
	g_global.redirection = NULL;
}
