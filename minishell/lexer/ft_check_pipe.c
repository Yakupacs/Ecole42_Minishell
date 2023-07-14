/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:14 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:06:15 by ikayacio         ###   ########.fr       */
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
