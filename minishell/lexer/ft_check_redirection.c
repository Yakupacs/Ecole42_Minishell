/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:18 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:08:29 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

int	is_redirection(char *line)
{
	int	len;

	len = 0;
	if (!*line)
		return (len);
	if (*line == '<' || *line == '>')
	{
		len++;
		if (*(line + 1) == '<' || *(line + 1) == '>')
		{
			len++;
			return (len);
		}
	}
	return (len);
}

void	check_redirection(t_command **tmp_line)
{
	t_command	*list;

	list = *tmp_line;
	while (list)
	{
		if (handle_character(&list, &is_redirection))
			list = list->next;
		else
			list = list->next;
		if (!list)
			break ;
		if (!list->next)
		{
			handle_character(&list, &is_redirection);
			list = list->next;
		}
	}
}
