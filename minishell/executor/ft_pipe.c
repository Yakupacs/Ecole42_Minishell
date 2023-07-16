/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:42 by yacis             #+#    #+#             */
/*   Updated: 2023/07/16 12:27:19 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_pipes(void)
{
	int	i;

	i = 0;
	g_global.all_pipe_fd = malloc(sizeof(int *) * (g_global.pipe_c));
	if (!g_global.all_pipe_fd)
		return ;
	while (i < g_global.pipe_c)
	{
		g_global.all_pipe_fd[i] = malloc(sizeof(int) * 2);
		pipe(g_global.all_pipe_fd[i]);
		i++;
	}
}

int	pipe_counter(void)
{
	t_command	*temp;
	int			i;

	temp = g_global.list;
	i = 0;
	while (temp)
	{
		if (temp->type == PIPE)
			i++;
		temp = temp->next;
	}
	g_global.pipe_c = i;
	if (g_global.pipe_c == 0)
		return (-1);
	return (0);
}

int	initialize_pipe(void)
{
	if (pipe_counter() == -1)
		return (-1);
	create_pipes();
	initialize_fork();
	return (0);
}
