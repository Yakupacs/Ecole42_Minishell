/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:04:46 by yacis             #+#    #+#             */
/*   Updated: 2023/07/15 00:04:47 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_msg(int flag, t_command *temp)
{
	char	*str;

	if (flag == 1)
	{
		if (temp->next == NULL)
			str = ft_strdup("newline");
		else
			str = ft_strdup(temp->next->arg);
		printf("Syntax Error: unexpected token '%s'\n", str);
		free(str);
		return (-1);
	}
	else if (flag == 2)
	{
		if (g_global.error_flag == -2)
			printf("Syntax Error: unexpected token '%s'\n", "<");
		if (g_global.error_flag == -1)
			printf("Syntax Error: quotes not closed!\n");
		return (-1);
	}
	else
		return (0);
}

int	error_check2(int flag, t_command *temp)
{
	while (temp)
	{
		if (temp->type == PIPE)
		{
			if (temp->next == NULL || temp->next->type == PIPE)
			{
				flag = 1;
				break ;
			}
		}
		else if (temp->type == INPUT_RDR || temp->type == OUTPUT_RDR
			|| temp->type == DOUBLE_INPUT_RDR
			|| temp->type == DOUBLE_OUTPUT_RDR)
		{
			if (temp->next == NULL
				|| (!(temp->next->type == WORD || temp->next->type == DOLLAR)))
			{
				flag = 1;
				break ;
			}
		}
		temp = temp->next;
	}
	return (flag);
}

int	check_error(void)
{
	int			flag;
	t_command	*tmp_list;

	flag = 0;
	tmp_list = g_global.list;
	if (g_global.error_flag)
		return (error_msg(2, tmp_list));
	if (!tmp_list)
		return (-1);
	if (tmp_list->type == PIPE)
	{
		error_msg(1, tmp_list);
		return (-1);
	}
	flag = error_check2(flag, tmp_list);
	if (error_msg(flag, tmp_list) == -1)
		return (-1);
	return (0);
}
