#include "../minishell.h"
#include "parse.h"

void	check_space(char *line, t_arg **tmp_line)
{
//	t_arg	*line_f;

	  check_double_quote(line);
	  check_single_quote(line);
    if (g_data.error_flag == -1)
		    return ;
    line = ft_strtrim(line, " ");
    split_line(line, *tmp_line);
}
