#include "../minishell.h"
#include "parse.h"

void	check_space(char *line, t_arg **tmp_line)
{
	if (check_quote(line) != 0)
	{
		g_data.error_flag = -1;
		return ;
	}
	line = ft_strtrim(line, " ");
	split_line(line, *tmp_line); 
	*tmp_line = (*tmp_line)->next;
}
