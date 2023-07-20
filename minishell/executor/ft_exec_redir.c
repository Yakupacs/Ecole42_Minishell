/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:34 by yacis             #+#    #+#             */
/*   Updated: 2023/07/20 19:24:12 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_shell(int status)
{
	if (status == 0)
		ft_execve();
	else
		perror("minishell");
}

void	exec_redir2(int status, char **redir, int i)
{
	if (ft_strcmp(redir[i], "<"))
	{
		g_global.fd = open(redir[i + 1], O_RDONLY, 0644);
		dup2(g_global.fd, 0);
		if (g_global.fd == -1)
		{
			printf("minishell: %s: No such file or directory\n",
				redir[i + 1]);
			exit(1);
		}
		if (g_global.command && !redir[i + 2])
			exec_shell(status);
		close(g_global.fd);
	}
	else if (ft_strcmp(redir[i], ">>"))
	{
		g_global.fd = open(redir[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		dup2(g_global.fd, 1);
		if (g_global.command[0] && !redir[i + 2]
			&& !ft_strcmp(g_global.command[0], "echo"))
			exec_shell(status);
		close(g_global.fd);
	}
}

void	exec_redir(int status)
{
	char	**rdr;
	int		i;

	rdr = g_global.redirection;
	i = 0;
	while (rdr[i])
	{
		if (ft_strcmp(rdr[i], ">"))
		{
			g_global.fd = open(rdr[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			dup2(g_global.fd, 1);
			if (g_global.command && !rdr[i + 2]
				&& !ft_strcmp(g_global.command[0], "echo"))
				exec_shell(status);
			close(g_global.fd);
		}
		else
			exec_redir2(status, rdr, i);
		if (g_global.fd == -1)
		{
			perror("minishell");
			exit(1);
		}
		i += 2;
	}
}
