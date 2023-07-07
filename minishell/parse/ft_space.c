#include "../minishell.h"
#include "parse.h"

void check_space(char *line, t_arg **tmp_line)
{
    //	t_arg	*line_f;

    if (check_quote(line) != 0)
    {
        g_data.error_flag = -1;
        return;
    }
    line = ft_strtrim(line, " ");
    split_line(line, *tmp_line);

    int i = 0;
    while (tmp_line[i]->content != NULL)
    {
        printf("content: %s\n", tmp_line[i]->content);
        i++;
    }
}
