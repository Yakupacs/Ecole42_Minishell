#include "../minishell.h"
#include "parse.h"

t_arg	*p_lstlast(t_arg *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	p_lstadd_back(t_arg **lst, t_arg *new)
{
	t_arg	*list;

	list = p_lstlast((*lst));
	if (!list)
		*lst = new;
	else
		list->next = new;
}

t_arg	*p_lstnew(int type, char *line)
{
	t_arg	*node;

	node = malloc (sizeof(t_arg));
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

int	p_lstsize(t_arg *lst)
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
