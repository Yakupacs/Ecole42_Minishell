/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:41 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:06:42 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

void	type_counter(t_command	**token)
{
	g_global.count_type = ft_calloc(1, sizeof(t_type_counter));
	while (*token)
	{
		if ((*token)->type == INPUT_RDR || (*token)->type == OUTPUT_RDR
			|| (*token)->type == DOUBLE_OUTPUT_RDR)
			g_global.count_type->rdr++;
		else if ((*token)->type == DOLLAR)
			g_global.count_type->dollar++;
		else if ((*token)->type == WORD)
			g_global.count_type->word++;
		else if ((*token)->type == DOUBLE_INPUT_RDR)
			g_global.count_type->heredoc++;
		else if ((*token)->type == PIPE)
			g_global.count_type->pipe++;
		(*token) = (*token)->next;
	}
}
