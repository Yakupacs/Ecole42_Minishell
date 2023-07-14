/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:36 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:13:57 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

int	is_space(char c)
{
	return (c == 32);
}

int	is_quotation(char *s)
{
	if (*s == '\"')
		return (1);
	else if (*s == '\'')
		return (2);
	return (0);
}

void	split_line(char *s, t_command *line)
{
	int	st;
	int	len;

	st = 0;
	len = 1;
	split_line2(st, len, s, line);
}

void	split_line2(int st, int len, char *line, t_command *s)
{
	int	i;

	i = -1;
	while (++i || 1)
	{
		if (is_quotation(&line[i]) == 1 && len++)
			while (!(is_quotation(&line[++i]) == 1) && line[i])
				len++;
		else if (is_quotation(&line[i]) == 2 && len++)
			while (!(is_quotation(&line[++i]) == 2) && line[i])
				len++;
		if (is_space(line[i]) || !line[i])
		{
			if (len != 1)
				p_lstadd_back(&s, p_lstnew(0, ft_substr(line, st, len - 1)));
			st = i + 1;
			len = 0;
		}
		if (!line[i])
			break ;
		len++;
	}
	free(line);
}
