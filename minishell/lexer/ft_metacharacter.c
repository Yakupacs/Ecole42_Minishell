/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metacharacter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:32 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:13:40 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

int	initialize_metacharacter(t_command *node)
{
	int	len;

	len = ft_strlen(node->arg);
	if (len == 1)
	{
		if (*node->arg == '<')
			node->type = INPUT_RDR;
		else if (*node->arg == '>')
			node->type = OUTPUT_RDR;
		else if (*node->arg == '|')
			node->type = PIPE;
	}
	if (len == 2)
	{
		if (*node->arg == '<' && *(node->arg + 1) == '<')
			node->type = DOUBLE_INPUT_RDR;
		else if (*node->arg == '>' && *(node->arg + 1) == '>')
			node->type = DOUBLE_OUTPUT_RDR;
		else
		{
			g_global.error_flag = -2;
			return (-2);
		}
	}
	return (0);
}
