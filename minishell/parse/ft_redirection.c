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

int	handle_character(t_arg **prompt, int (*checker)(char *))
{
	int		i;
	int		len;
	char	*s;

	s = (*prompt)->arg;
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
			//append_list(prompt, i, len);
			return (1);
		}
		if (!s[i])
			break ;
	}
	return (0);
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