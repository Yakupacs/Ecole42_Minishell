/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:31 by yacis             #+#    #+#             */
/*   Updated: 2023/07/15 17:45:44 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_command_line2(t_command *temp, int i, int j)
{
	while (temp && temp->type != PIPE)
	{
		if (temp->type == WORD || temp->type == DOLLAR)
			g_global.command[i++] = ft_strdup(temp->arg);
		else if (temp->type == DOUBLE_INPUT_RDR)
			temp = temp->next;
		else if (temp->type == OUTPUT_RDR || temp->type == INPUT_RDR
			|| temp->type == DOUBLE_OUTPUT_RDR)
		{
			g_global.redirection[j++] = ft_strdup(temp->arg);
			g_global.redirection[j++] = ft_strdup(temp->next->arg);
			temp = temp->next;
		}
		temp = temp->next;
	}
	g_global.list = temp;
	if (i > 0)
		g_global.command[i] = NULL;
	if (j > 0)
		g_global.redirection[j] = NULL;
	if (!temp)
		return ;
	if (g_global.list->type == PIPE)
		g_global.list = g_global.list->next;
}

void	ft_command_redirection_len(t_command *temp, int i, int j)
{
	while (temp && temp->type != PIPE)
	{
		if (temp->type == WORD || temp->type == DOLLAR)
			i++;
		else if (temp->type == DOUBLE_INPUT_RDR)
			temp = temp->next;
		else if (temp->type == OUTPUT_RDR || temp->type == INPUT_RDR
			|| temp->type == DOUBLE_OUTPUT_RDR)
		{
			j += 2;
			temp = temp->next;
		}
		temp = temp->next;
	}
	g_global.list = temp;
	if (i > 0)
		g_global.command = malloc(sizeof(char *) * i + 1);
	if (j > 0)
		g_global.redirection = malloc(sizeof(char *) * j + 1);
	if (!temp)
		return ;
	if (g_global.list->type == PIPE)
		g_global.list = g_global.list->next;
}

void	ft_command_line(void)
{
	t_command	*temp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	temp = g_global.list;
	ft_command_redirection_len(temp, i, j);
	ft_command_line2(temp, i, j);
}
