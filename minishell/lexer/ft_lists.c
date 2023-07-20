/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:29 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/20 17:54:27 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

t_command	*p_lstlast(t_command *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	p_lstadd_back(t_command **lst, t_command *new)
{
	t_command	*list;

	list = p_lstlast((*lst));
	if (!list)
		*lst = new;
	else
		list->next = new;
}

t_command	*p_lstnew(int type, char *line)
{
	t_command	*node;

	node = malloc (sizeof(t_command));
	if (!node)
	{
		free(line);
		free(node);
		return (0);
	}
	node->arg = ft_strdup(line);
	node->type = type;
	node->next = NULL;
	free(line);
	return (node);
}

int	p_lstsize(t_command *lst)
{
	int	i;

	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
