/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:14 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/24 11:30:15 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

int	is_pipe(char *s)
{
	if (*s == '|')
		return (1);
	return (0);
}

void	check_pipe(t_command **prompt)
{
	t_command	*iter;

	iter = *prompt;
	while (iter)
	{
		if (handle_character(&iter, &is_pipe))
			iter = iter->next;
		else
			iter = iter->next;
		if (!iter)
			break ;
		if (!iter->next)
		{
			handle_character(&iter, &is_pipe);
			iter = iter->next;
		}
	}
}
