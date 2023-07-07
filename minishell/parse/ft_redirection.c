#include "../minishell.h"
#include "parse.h"

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

void	check_redirection(t_arg **tmp_line)
{
	t_arg	*list;

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