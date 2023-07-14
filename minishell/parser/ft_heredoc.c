/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:52 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:12:38 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_heredoc_readline(int i)
{
	while (1)
	{
		g_global.here_line = readline("> ");
		if (ft_strcmp(g_global.here_line, g_global.heredoc[i]))
			break ;
		else
		{
			if (g_global.count_type->heredoc == (((i - 1) / 2) + 1))
			{
				ft_putstr_fd(g_global.here_line, g_global.here_fd[1]);
				ft_putstr_fd("\n", g_global.here_fd[1]);
				g_global.main_here_size += ft_strlen(g_global.here_line);
			}
			free(g_global.here_line);
		}
	}
	close(g_global.here_fd[1]);
}

void	ft_heredoc_start(void)
{
	int	i;
	int	status;

	i = 0;
	while (i == 0 || g_global.heredoc[i])
	{
		status = fork();
		if (status == 0)
		{
			close(g_global.here_fd[0]);
			ft_heredoc_readline(i + 1);
			exit(0);
		}
		else
			waitpid(status, &g_global.exit_status, 0);
		i += 2;
	}
	close(g_global.here_fd[1]);
}

void	init_pipe(void)
{
	g_global.here_fd = malloc(sizeof(int) * 2);
	pipe(g_global.here_fd);
}

void	ft_heredoc(void)
{
	t_command	*temp;
	int			i;

	temp = g_global.list;
	init_pipe();
	g_global.heredoc = malloc(sizeof(char *)
			* (g_global.count_type->heredoc * 2 + 1));
	i = 0;
	while (temp)
	{
		if (temp->type == DOUBLE_INPUT_RDR && temp->next)
		{
			g_global.heredoc[i++] = ft_strdup(temp->arg);
			g_global.heredoc[i++] = ft_strdup(temp->next->arg);
		}
		temp = temp->next;
	}
	g_global.heredoc[i] = NULL;
	if (i > 0)
		ft_heredoc_start();
	else
		return ;
}
