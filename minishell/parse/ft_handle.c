#include "../minishell.h"
#include "parse.h"


t_arg	*create_front(int st, int len, t_arg **list, t_arg *tmp)
{
	t_arg	*front;

	front = p_lstnew(0, ft_substr((*list)->arg, (st + len),
				(ft_strlen((*list)->arg) - (st + len))));
	if (*front->arg)
		front->next = tmp;
	else
	{
		free(front->arg);
		free(front);
		front = tmp;
	}
	return (front);
}

void	*append_list(t_arg **list, int st, int len)
{
	char	*back;
	char	*rdr;
	t_arg	*front;
	t_arg	*tmp;

	tmp = (*list)->next;
	front = create_front(st, len, list, tmp);
	rdr = ft_substr((*list)->arg, st, len);
	if (st != 0)
	{
		back = ft_substr((*list)->arg, 0, st);
		free((*list)->arg);
		(*list)->arg = back;
		(*list)->next = p_lstnew(0, rdr);
		(*list)->next->next = front;
	}
	else
	{
		free((*list)->arg);
		(*list)->arg = rdr;
		(*list)->next = front;
	}
	return (NULL);
}

int	handle_character(t_arg **list, int (*checker)(char *))
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
			if (len == -1)
				exit (1);
			append_list(list, i, len);
			return (1);
		}
		if (!s[i])
			break ;
	}
	return (0);
}