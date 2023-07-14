/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quot_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:34 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:13:28 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

void	quot_cleaner(t_command **token)
{
	t_command	*node;
	char		*s;

	node = *token;
	while (node)
	{
		if (contains_quot(node->arg))
		{
			if (node->type != DOLLAR)
			{
				s = node->arg;
				node->arg = trim_quot(node->arg);
				free(s);
			}
		}
		node = node->next;
	}
}
