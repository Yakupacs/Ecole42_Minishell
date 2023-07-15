/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:04:51 by yacis             #+#    #+#             */
/*   Updated: 2023/07/15 19:31:43 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_all2(void)
{
	int	i;

	i = 0;
	if (g_global.redirection)
	{
		while (g_global.redirection[i])
			free(g_global.redirection[i++]);
		free(g_global.redirection);
	}
	if (g_global.count_type)
		free(g_global.count_type);
	i = 0;
	if (g_global.heredoc)
	{
		while (g_global.heredoc[i])
			free(g_global.heredoc[i++]);
		free(g_global.heredoc);
	}
}

void	ft_free_all(void)
{
	int	i;

	ft_free_all2();
	i = 0;
	if (g_global.command)
	{
		while (g_global.command[i])
			free(g_global.command[i++]);
		free(g_global.command);
	}
}

void	freeliazer(t_command *temp)
{
	t_command	*tmp;

	tmp = NULL;
	ft_free_all();
	if (g_global.here_fd)
		free(g_global.here_fd);
	if (temp)
	{
		while (temp)
		{
			tmp = temp;
			free(tmp->arg);
			temp = temp->next;
			free(tmp);
		}
	}
}
