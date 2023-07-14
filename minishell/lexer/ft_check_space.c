/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:21 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:06:22 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

void	check_space(char *line, t_command **tmp_line)
{
	t_command	*line_f;

	if (check_quote(line) != 0)
	{
		g_global.error_flag = -1;
		return ;
	}
	line = ft_strtrim(line, " ");
	split_line(line, *tmp_line); 
	line_f = *tmp_line;
	*tmp_line = (*tmp_line)->next;
	free(line_f);
}
