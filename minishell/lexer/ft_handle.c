/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:23 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/24 14:38:20 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

t_command	*create_back(int st, int len, t_command **list, t_command *tmp)
{
	t_command	*back;

	back = p_lstnew(0, ft_substr((*list)->arg, (st + len),
				(ft_strlen((*list)->arg) - (st + len))));
	if (*back->arg)
		back->next = tmp;
	else
	{
		free(back->arg);
		free(back);
		back = tmp;
	}
	return (back);
}

void	*append_list(t_command **list, int st, int len)
{
	char		*front;
	char		*rdr;
	t_command	*back;
	t_command	*tmp;

	tmp = (*list)->next;
	back = create_back(st, len, list, tmp);
	rdr = ft_substr((*list)->arg, st, len);
	if (st != 0)
	{
		front = ft_substr((*list)->arg, 0, st);
		free((*list)->arg);
		(*list)->arg = front;
		(*list)->next = p_lstnew(0, rdr);
		(*list)->next->next = back;
	}
	else
	{
		free((*list)->arg);
		(*list)->arg = rdr;
		(*list)->next = back;
	}
	return (NULL);
}

int	handle_character(t_command **list, int (*checker)(char *))
{
	int		i;
	int		len;
	char	*s;

	s = (*list)->arg;
	if (!s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (is_quotation(&s[i]))
			while (!is_quotation(&s[++i]) && s[i])
				;
		if (checker && checker(&s[i]))
		{
			len = checker(&s[i]);
			append_list(list, i, len);
			return (1);
		}
		if (!s[i])
			break ;
	}
	return (0);
}
